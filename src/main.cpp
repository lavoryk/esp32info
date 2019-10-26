#include <Arduino.h>

uint64_t chipid;
void setup() 
{
  Serial.begin(115200);
  delay(10);
  
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  Serial.println("--esp_chip_info--");
  Serial.printf("revision %d\n", chip_info.revision);
  Serial.printf("model %d\n", chip_info.model);
  Serial.printf("cores %d\n", chip_info.cores);
  Serial.printf("features %d\n", chip_info.features);
  Serial.print("Chip has embedded flash memory: "); Serial.println(CHIP_FEATURE_EMB_FLASH&chip_info.features ? "yes": "no");
  Serial.print("Chip has 2.4GHz WiFi: "); Serial.println(CHIP_FEATURE_WIFI_BGN&chip_info.features ? "yes": "no");
  Serial.print("Chip has Bluetooth LE: "); Serial.println(CHIP_FEATURE_BLE&chip_info.features ? "yes": "no");
  Serial.print("Chip has Bluetooth Classic: "); Serial.println(CHIP_FEATURE_BT&chip_info.features ? "yes": "no");
  Serial.println("-----------------");  
  Serial.printf("EspClass::getChipRevision %d\n", ESP.getChipRevision());
  Serial.printf("EspClass::getCpuFreqMHz %d\n", ESP.getCpuFreqMHz());
  Serial.printf("EspClass::getSdkVersion %s\n", ESP.getSdkVersion());
  Serial.printf("EspClass::getFlashChipSize %d\n", ESP.getFlashChipSize());
  Serial.printf("EspClass::getFlashChipSpeed %d\n", ESP.getFlashChipSpeed());
  Serial.printf("EspClass::getFlashChipMode %d\n", ESP.getFlashChipMode());

  // Try to change cpu frequency
  setCpuFrequencyMhz(240);

}

void loop() 
{
  chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
  Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));//print High 2 bytes
  Serial.printf("%08X\n",(uint32_t)chipid);//print Low 4bytes.
  delay(2000);
}