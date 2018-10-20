/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "altera_up_avalon_character_lcd.h"
#include "system.h"
#include "sys/alt_stdio.h"
#include "io.h"


void delay(int a){
	volatile int i = 0;
	while(i<a*10000){
		i++;
	}
}

void clear();

int main(void)
{
	int i;
	int j;
	int control = 0;
	int ct=0;
	alt_up_character_lcd_dev * char_lcd_dev;
	// open the Character LCD port
	char_lcd_dev = alt_up_character_lcd_open_dev ("/dev/character_lcd_0");
	if ( char_lcd_dev == NULL)
		alt_printf ("Error: could not open character LCD device\n");
	else
	alt_printf ("Opened character LCD device\n");
	/* Initialize the character display */
	alt_up_character_lcd_init (char_lcd_dev);
	/* Write "Welcome to" in the first row */
	//alt_up_character_lcd_string(char_lcd_dev, "Tou com fome");
	/* Write "the DE2 board" in the second row */
	//char second_row[] = "Quero Tomada";
	//alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 1);
	//alt_up_character_lcd_string(char_lcd_dev, second_row);
	unsigned int entrada;
	  unsigned int led_on;
	  //IOWR(PIN_SAIDA_BASE, 0, 7);
	  led_on = 7;
	  /* Event loop never exits. */
	  while (1){

		  entrada = IORD(PIN_ENTRADA_BASE, 0);
		  //IOWR(PIN_SAIDA_BASE,0,entrada);
		  if(entrada==14 && control == 0){ //botão 1 pressionado
			  switch(led_on){
			  	  case 7:
			  		//IOWR(PIN_SAIDA_BASE,0,14);
					for(i=0;i<16;i++){
						for(j=0;j<2;j++)
							alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
					}
					alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
			  		alt_up_character_lcd_string(char_lcd_dev, "OPCAO 4");
			  		delay(50);
			  		led_on = 14;
			  		break;

			  	  case 11:
			  		//IOWR(PIN_SAIDA_BASE,0,7);
					for(i=0;i<16;i++){
						for(j=0;j<2;j++)
							alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
					}
					alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
			  		alt_up_character_lcd_string(char_lcd_dev, "OPCAO 1");
			  		delay(50);
			  		led_on = 7;
			  		break;

			  	  case 13:
			  		//IOWR(PIN_SAIDA_BASE,0,11);
					for(i=0;i<16;i++){
						for(j=0;j<2;j++)
							alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
					}
					alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
			  		alt_up_character_lcd_string(char_lcd_dev, "OPCAO 2");
			  		delay(50);
			  		led_on = 11;
			  		break;

			  	  case 14:
			  		//IOWR(PIN_SAIDA_BASE,0,13);
					for(i=0;i<16;i++){
						for(j=0;j<2;j++)
							alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
					}
					alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
			  		alt_up_character_lcd_string(char_lcd_dev, "OPCAO 3");
			  		delay(50);
			  		led_on = 13;
			  		break;
			  }
		  }
		  else if(entrada == 13 && control == 0){
				  switch(led_on){
					  case 7:
						//IOWR(PIN_SAIDA_BASE,0,11);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "OPCAO 2");
						delay(50);
						led_on = 11;
						break;

					  case 11:
						//IOWR(PIN_SAIDA_BASE,0,13);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "OPCAO 3");
						delay(50);
						led_on = 13;
						break;

					  case 13:
						//IOWR(PIN_SAIDA_BASE,0,14);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "OPCAO 4");
						delay(50);
						led_on = 14;
						break;

					  case 14:
						//IOWR(PIN_SAIDA_BASE,0,7);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "OPCAO 1");
						delay(50);
						led_on = 7;
						break;
				  }
			  }else if(entrada == 11){
				  switch(led_on){
					  case 7:
						//IOWR(PIN_SAIDA_BASE,0,7);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "MENSAGEM 1");
						IOWR(PIN_SAIDA_BASE,0,14);
						control = 1;
						delay(50);
						break;

					  case 11:
						//IOWR(PIN_SAIDA_BASE,0,11);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "MENSAGEM 2");
						IOWR(PIN_SAIDA_BASE,0,13);
						if(entrada == 13 || entrada == 14){
							alt_up_character_lcd_string(char_lcd_dev, "MENSAGEM 2");
						}
						control = 2;
						delay(50);
						break;

					  case 13:
						//IOWR(PIN_SAIDA_BASE,0,13);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "MENSAGEM 3");
						IOWR(PIN_SAIDA_BASE,0,11);
						if(entrada == 13 || entrada == 14){
							alt_up_character_lcd_string(char_lcd_dev, "MENSAGEM 3");

						}
						control = 3;
						delay(50);
						break;

					  case 14:
						//IOWR(PIN_SAIDA_BASE,0,14);
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
							alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						alt_up_character_lcd_string(char_lcd_dev, "MENSAGEM 4");
						IOWR(PIN_SAIDA_BASE,0,7);
						if(entrada == 13 || entrada == 14){
							alt_up_character_lcd_string(char_lcd_dev, "MENSAGEM 4");
							IOWR(PIN_SAIDA_BASE,0,14);
						}
						control = 4;
						delay(50);
						break;

				  }

			  }else if(entrada == 7 && control != 0){

				  switch(control){
					  case 1:
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						  alt_up_character_lcd_string(char_lcd_dev, "OPCAO 1");
						  control = 0;
						  break;
					  case 2:
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						  alt_up_character_lcd_string(char_lcd_dev, "OPCAO 2");
						  control = 0;
						  break;
					  case 3:
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						  alt_up_character_lcd_string(char_lcd_dev, "OPCAO 3");
						  control = 0;
						  break;
					  case 4:
						for(i=0;i<16;i++){
							for(j=0;j<2;j++)
								alt_up_character_lcd_erase_pos(char_lcd_dev, i, j);
						}
						alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
						  alt_up_character_lcd_string(char_lcd_dev, "OPCAO 4");
						  control = 0;
						  break;
				  }

		  }
	  }

	  return 0;
}
