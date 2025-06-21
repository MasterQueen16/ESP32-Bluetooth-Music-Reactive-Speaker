#include <BluetoothA2DPSink.h>
BluetoothA2DPSink a2dp_sink;

// Define RGB LED pins and channels
#define RED_PIN     2
#define GREEN_PIN   4
#define BLUE_PIN    5

#define RED_CH      0
#define GREEN_CH    1
#define BLUE_CH     2

uint8_t redValue = 0;
uint8_t greenValue = 0;
uint8_t blueValue = 0;

void setup() {
  Serial.begin(115200);

  // Setup PWM
  ledcSetup(RED_CH, 5000, 8);
  ledcSetup(GREEN_CH, 5000, 8);
  ledcSetup(BLUE_CH, 5000, 8);

  ledcAttachPin(RED_PIN, RED_CH);
  ledcAttachPin(GREEN_PIN, GREEN_CH);
  ledcAttachPin(BLUE_PIN, BLUE_CH);

  // Setup A2DP streaming
  a2dp_sink.set_stream_reader(audio_data_callback, true);
  a2dp_sink.set_output(i2s_output);  // Instead of set_output_mode
  a2dp_sink.set_volume(90);
  a2dp_sink.start("ESP32_Music_Light");
}

void i2s_output(const uint8_t* data, uint32_t len) {
  size_t bytes_written;
  i2s_write((i2s_port_t)0, data, len, &bytes_written, portMAX_DELAY);
}

void loop() {
  // Update PWM output
  ledcWrite(RED_CH, redValue);
  ledcWrite(GREEN_CH, greenValue);
  ledcWrite(BLUE_CH, blueValue);
  delay(10);
}

// Analyze audio buffer and set LED brightness
void audio_data_callback(const uint8_t *data, uint32_t len) {
  uint32_t sum = 0;

  // Simple average amplitude calculation
  for (uint32_t i = 0; i < len; i++) {
    sum += abs((int16_t)data[i]);
  }

  int avg = sum / len;

  // Map volume level to RGB values
  redValue   = constrain(map(avg, 0, 128, 0, 255), 0, 255);
  greenValue = constrain(map(avg, 64, 192, 0, 255), 0, 255);
  blueValue  = constrain(map(avg, 128, 255, 0, 255), 0, 255);
}
