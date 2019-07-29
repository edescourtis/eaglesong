#ifndef __EAGLESONG_H__
#define __EAGLESONG_H__
void PrintState( uint32_t * state );
void EaglesongPermutation( uint32_t * state );
void EaglesongSponge( unsigned char * output, unsigned int output_length, const unsigned char * input, unsigned int input_length, unsigned char delimiter );
void EaglesongHash( unsigned char * output, const unsigned char * input, unsigned int input_length);
#endif
