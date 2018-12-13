/************************************************************************
 *																		*
 *		FILE NAME: main.c											*
 *		PURPOSE:														*
 *		FILE REFERENCES:												*
 *																		*
 *		Name			I/O			Description							*
 *		----			---			-----------							*
 *																		*
 *		EXTERNAL VARIABLES:												*
 *																		*
 *		Name	Type	I/O			Description							*
 *		----	----	---			----------- 						*
 *																		*
 *		EXTERNAL REFERENCES:											*
 *																		*
 *		Name						Description							*
 *		----						-----------							*
 *																		*
 * 		ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES: 	*
 *																		*
 * 		ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:							*
 *																		*
 *		NOTES:															*
 *																		*
 * 		REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:				*
 *																		*
 * 		DEVELOPMENT HISTORY:											*
 *																		*
 *		Date	Author	Change ID	Release		Description of change	*
 *		Dec 11, 2018	joaorodrigues													*
 *																		*
 * 		ALGORITHM (PDL)													*
 *																		*
 ************************************************************************/

#include <SPI_comms.h>
#include <I2C_comms.h>
#include <LCD1602A.h>
#include <Shift_Strings.h>

#define F_CPU 16000000UL

int main(void) {
	//ScreenInit(SPI);
	_delay_ms(1);
	ScreenInit(I2C);
	_delay_ms(1);

	/* Display ON, Cursor Blink */

	uint8_t command;

	command = LCD_DISP_ON_BLINK;
	//ScreenInstruction(command, SPI);
	_delay_ms(1);
	ScreenInstruction(command, I2C);

	/* Print a string */

	uint8_t string1[16] = "ABCDEFGHIJKLMNOP";
	uint8_t string2[16] = "";

	while (1) {
		ShiftString(string1, string2);

		//PutString(string1, sizeof(string1) - 1, SPI);
		_delay_ms(1);
		PutString(string1, sizeof(string1) - 1, I2C);

		_delay_ms(10000);

		//ScreenInstruction(LCD_DISP_CLEAR, SPI);
		_delay_ms(1);
		ScreenInstruction(LCD_DISP_CLEAR, I2C);
		_delay_ms(1000);
	}

	return 0;
}
