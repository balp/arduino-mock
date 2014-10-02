/** Implementation of EEPROM mock **/

#include "arduino-mock/eeprom.h"

static MockEEPROM* p_MockEEPROM = NULL;
MockEEPROM* MockEEPROMInstance()
{
	if (!p_MockEEPROM){
		p_MockEEPROM = new MockEEPROM();
		}
	return p_MockEEPROM;
}

void releaseMockEEPROM()
{
	if (p_MockEEPROM){
		delete p_MockEEPROM;
		p_MockEEPROM = NULL;
	}
}

uint8_t EEPROM::read(int a){
	return p_MockEEPROM->read(a);
}

void EEPROM::write(int a, uint8_t b){
	p_MockEEPROM->write(a, b);
}