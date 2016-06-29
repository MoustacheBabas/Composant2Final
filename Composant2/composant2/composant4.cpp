#include "stdafx.h"
#include "bloc.h"
#include <stdlib.h> 
#include <iostream> 
#include <vector>

unsigned char* hash(int nBloc, int nTx, int nUTXO, float montant, unsigned char destinataire[])
{
	unsigned char s[64];
	s[0] = 'a';
	s[1] = 'q';
	s[2] = 'p';
	s[3] = 'o';
	s[4] = 'i';
	s[5] = 'u';
	s[6] = 'y';
	s[7] = 't';
	s[8] = 'r';
	s[9] = 'e';
	s[10] = 'z';
	s[11] = 'a';
	s[12] = 'n';
	s[13] = 'b';
	s[14] = 'v';
	s[15] = 'c';
	s[16] = 'x';
	s[17] = 'w';
	s[18] = 'm';
	s[19] = 'l';
	s[20] = 'k';
	s[21] = 'j';
	s[22] = 'h';
	s[23] = 'g';
	s[24] = 'f';
	s[25] = 'd';
	s[26] = 's';
	s[27] = 'q';
	s[28] = 'p';
	s[29] = 'o';
	s[30] = 'i';
	s[31] = 'u';
	s[32] = 'y';
	s[33] = 't';
	s[34] = 'r';
	s[35] = 'e';
	s[36] = 'z';
	s[37] = 'a';
	s[38] = 'n';
	s[39] = 'b';
	s[40] = 'v';
	s[41] = 'c';
	s[42] = 'x';
	s[43] = 'w';
	s[44] = 'm';
	s[45] = 'l';
	s[46] = 'k';
	s[47] = 'j';
	s[48] = 'h';
	s[49] = 'g';
	s[50] = 'f';
	s[51] = 'd';
	s[52] = 's';
	s[53] = 'q';
	s[54] = 'p';
	s[55] = 'o';
	s[56] = 'i';
	s[57] = 'u';
	s[58] = 'y';
	s[59] = 't';
	s[60] = 'r';
	s[61] = 'e';
	s[62] = 'z';
	s[63] = 'a';

	return s;
}