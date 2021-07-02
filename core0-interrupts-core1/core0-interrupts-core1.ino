/*
 * Arduino IDE for RP2040: d:\dev\raspberry-pi\rp2040\arduino-1.8.15
 */

const int gpio_pin = 14;

void gpio_callback(uint gpio, uint32_t events)
{
  // events:
  // 0x01 = LEVEL_LOW
  // 0x02 = LEVEL_HIGH
  // 0x04 = EDGE_FALL
  // 0x08 = EDGE_RISE
  digitalWrite(gpio_pin,LOW);
  Serial.printf("core%d - GPIO %d 0x%x\n",get_core_num(),gpio,events);
}

// Core 0
void setup(void) 
{
  //pinMode(gpio_pin,INPUT_PULLUP);
  pinMode(gpio_pin,OUTPUT);
  digitalWrite(gpio_pin,LOW);
}

void loop(void) 
{
  Serial.printf("core%d running\n",get_core_num());
  digitalWrite(gpio_pin,HIGH);
  delay(1100);
}

// Core 1
void setup1(void)
{
  //gpio_set_irq_enabled_with_callback(gpio_pin,GPIO_IRQ_EDGE_FALL,true,&gpio_callback);
  gpio_set_irq_enabled_with_callback(gpio_pin,GPIO_IRQ_LEVEL_HIGH,true,gpio_callback);
}

void loop1(void)
{
  delay(10);
  //Serial.printf("core%d running\n",get_core_num());
}
