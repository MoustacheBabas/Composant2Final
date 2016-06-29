#include "StdAfx.h"
#include "stdafx.h"
#include "composant1.h"
#include "composant2.h"
#include "bloc.h"
#include <stdlib.h>
#include <vector>
#include <iostream> 

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned char ePrivateKey[4];
	unsigned char ePublicKey[4];
	unsigned char dPublicKey[4];

	ePrivateKey[0] = 'a';
	ePrivateKey[1] = 'a';
	ePrivateKey[2] = 'a';
	ePrivateKey[3] = 'a';

	ePublicKey[0] = 'a';
	ePublicKey[1] = 'a';
	ePublicKey[2] = 'a';
	ePublicKey[3] = 'a';

	dPublicKey[0] = 'a';
	dPublicKey[1] = 'a';
	dPublicKey[2] = 'a';
	dPublicKey[3] = 'a';

	// Valeure négative
	createTransaction(ePrivateKey, ePublicKey, dPublicKey, -1);

	// Valeure nulle
	createTransaction(ePrivateKey, ePublicKey, dPublicKey, 0);

	// Montant disponible insuffisant
	createTransaction(ePrivateKey, ePublicKey, dPublicKey, 100);

	//Ok
	createTransaction(ePrivateKey, ePublicKey, dPublicKey, 1);

	system("pause");
	return 0;
}