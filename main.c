#include <main.h>

void main()
{
   lcd_init();
   lcd_clear();
   
   int16 adc;
   float voltage;
   char string[17];
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SETUP_ADC_PORTS(ALL_ANALOG);
   SET_ADC_CHANNEL(5); //RE0 AN5
   
   while(TRUE)
   {
      //TODO: User Code
      adc =read_adc();
      /*
         cu 5V thi doc gia tri max adc la 1023
         cu xV thi doc gia tri adc
         vay dien ap x = 5*adc/1023
      */
      voltage = 5.0f*adc/1023.0f;
      //voltage = ceil(voltage); //lam tron dien ap
      
      lcd_gotoxy(1,1);
      sprintf(string,"DIEN AP: %1.4f",voltage);
      //%1.yf voi y la bao nhieu chu so thap phan sau dau phay
      lcd_puts(string);
      delay_ms(500);
   }

}
