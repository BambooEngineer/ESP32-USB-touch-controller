// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
#include <stdio.h>
#include "driver/touch_pad.h"
//#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define TOUCH_PAD_NO_CHANGE   (-1)
#define TOUCH_THRESH_NO_USE   (0)
#define TOUCHPAD_FILTER_TOUCH_PERIOD (10)

static uint16_t up_value;
static uint16_t down_value;
static uint16_t l_value;
static uint16_t r_value;
static uint16_t a_value;
static uint16_t b_value;
static uint16_t x_value;
static uint16_t y_value;

const char u = 'u';
const char d = 'd';
const char l = 'l';
const char r = 'r';
const char a = 'a';
const char b = 'b';
const char x = 'x';
const char y = 'y';

bool one=false;
bool two=false;
bool three=false; 
bool four=false;
bool five=false;
bool six=false;
bool seven=false;
bool eight=false;


// UART COMMUNICATION 

//const uart_port_t uart_num = UART_NUM_2;
//const int uart_buffer_size = (1024 * 2);


  /*  Touch0 >> GPIO4
    Touch3 >> GPIO15
    Touch4 >> GPIO13
    Touch5 >> GPIO12 
    Touch6 >> GPIO14
    Touch7 >> GPIO27
    Touch8 >> GPIO33
    Touch9 >> GPIO32
*/

//uart_config_t uart_config = {
  //  .baud_rate = 115200,
   // .data_bits = UART_DATA_8_BITS,
  //  .parity = UART_PARITY_DISABLE,
  //  .stop_bits = UART_STOP_BITS_1,
  //  .flow_ctrl = UART_HW_FLOWCTRL_CTS_RTS,
  //  .rx_flow_ctrl_thresh = 122,
 //};

static void tp_example_read_task(touch_pad_t i, uint16_t value, const char a, bool *x) // why do the parameter variables have the correct values but not the variables in the parameters
{
    
    //printf("Touch Sensor filter mode read, the output format is: \nTouchpad num:[raw data, filtered data]\n\n");
    //printf("Touch Sensor normal mode read, the output format is: \nTouchpad num:[raw data]\n\n");
    // Write data to UART.
  
  

    
            // If open the filter mode, please use this API to get the touch pad count.
            touch_pad_read_raw_data(i, &value);
            //touch_pad_read_filtered(i, &filter_value);
            //printf("T%d:[%4d,%4d] ", i, value, filter_value);
            if(value < 800){
              *x = false; 
              Serial.print(a);
              delay(100);
              //uart_write_bytes(uart_num, (const char*)a, sizeof(a));
            }
            else{
              *x = true; // the booleans in the parameters are not affected on the outside of the function unless pointers and addresses are used NICE TIP
            }
            //touch_pad_read(i, &value);
            
            //printf("T%d:[%4d] \n", i, value);
           
        
        //printf("\n");
        //delay(200 / portTICK_PERIOD_MS);
    
}

static void tp_example_touch_pad_init(touch_pad_t i)
{
    
        touch_pad_config(i, TOUCH_THRESH_NO_USE);
    
}

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time 
  
  
// Configure UART parameters
  //ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
  ESP_ERROR_CHECK(touch_pad_init());
    // Set reference voltage for charging/discharging
    // In this case, the high reference valtage will be 2.7V - 1V = 1.7V
    // The low reference voltage will be 0.5
    // The larger the range, the larger the pulse count value.
  touch_pad_set_voltage(TOUCH_HVOLT_2V7, TOUCH_LVOLT_0V5, TOUCH_HVOLT_ATTEN_1V);
  tp_example_touch_pad_init(TOUCH_PAD_NUM0);
  tp_example_touch_pad_init(TOUCH_PAD_NUM3);
  tp_example_touch_pad_init(TOUCH_PAD_NUM4);
  tp_example_touch_pad_init(TOUCH_PAD_NUM5);
  tp_example_touch_pad_init(TOUCH_PAD_NUM6);
  tp_example_touch_pad_init(TOUCH_PAD_NUM7);
  tp_example_touch_pad_init(TOUCH_PAD_NUM8);
  tp_example_touch_pad_init(TOUCH_PAD_NUM9);
  touch_pad_filter_start(TOUCHPAD_FILTER_TOUCH_PERIOD);

  //QueueHandle_t uart_queue;
  // Install UART driver using an event queue here
  //ESP_ERROR_CHECK(uart_driver_install(UART_NUM_2, uart_buffer_size, \
                                        uart_buffer_size, 10, &uart_queue, 0));
    
}


void loop()
{

   tp_example_read_task(TOUCH_PAD_NUM0, l_value, l, &one);
   tp_example_read_task(TOUCH_PAD_NUM3, r_value, r, &two);
   tp_example_read_task(TOUCH_PAD_NUM4, up_value, u, &three);
   tp_example_read_task(TOUCH_PAD_NUM5, down_value, d, &four);
   tp_example_read_task(TOUCH_PAD_NUM6, a_value, a, &five);
   tp_example_read_task(TOUCH_PAD_NUM7, b_value, b, &six);
   tp_example_read_task(TOUCH_PAD_NUM8, x_value, x, &seven);
   tp_example_read_task(TOUCH_PAD_NUM9, y_value, y, &eight);
   
  // if(one && two && three && four && five && six && seven && eight){
    //Serial.print('z');
    //delay(100);
  // }
   
  
 
}
