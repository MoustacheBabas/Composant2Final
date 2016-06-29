// composant2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "composant1.h"
#include "composant3.h"
#include "composant4.h"
#include "composant5.h"
#include "composant6.h"
#include "bloc.h"
#include <stdlib.h>
#include <vector>
#include <iostream> 


std::vector<UTXO> getUTXO0(Bloc b)
{
	std::vector<UTXO> vec;
	vec.push_back(b.tx1.utxo[0]);
	vec.push_back(b.tx1.utxo[1]);

	return vec;
}

int getNbBlocMax(std::vector<Bloc> vb)
{

	int j = 0;

	for each( Bloc b in vb)
	{
		if(blockVerify(b, ""))
		{
			if(j < b.num)
			{
				j = b.num;
			}
		}
	}

	return j;
}

std::vector<UTXO> getAllUTXO(std::vector<Bloc> vb)
{
	std::vector<UTXO> utxo;

	for each( Bloc b in vb)
	{
		if(blockVerify(b, ""))
		{
			utxo.push_back(b.tx1.utxo[0]);

			if(b.tx1.utxo[1].montant != 0)
			{
				utxo.push_back(b.tx1.utxo[1]);
			}
		}
	}

	return utxo;
}

float verifyAmount(unsigned char key[4])
{
	std::vector<UTXO> utxo;
	int j = 0;
	// On reçoit les blocs du composant 1 avec getBlocs
	std::vector<Bloc> blocs = getBlocs();
	float montant = 0.0f;
	
	utxo = getAllUTXO(blocs);
	
	for each( UTXO xo in utxo)
	{
		if((xo.dest[0] == key[0]) && (xo.dest[1] == key[1]) && (xo.dest[2] == key[2]) && (xo.dest[3] == key[3]))
		{
			montant += xo.montant;
		}
	}

	return montant;
}


bool createTransaction(unsigned char ePrivateKey[4], unsigned char ePublicKey[4], unsigned char dPublicKey[4], float montant)
{
	Bloc b;
	
	int numBloc = getNbBlocMax(getBlocs());
	
	if(montant <= verifyAmount(ePublicKey) && montant > 0)
	{
		b.num = numBloc;
		
		b.tx1.txi[0].nBloc = numBloc;
		b.tx1.txi[0].nTx = 1;
		b.tx1.txi[0].nUtxo = 2;
		for(int i = 0; i < 64 ; i ++)
		{
	
			b.tx1.txi[0].signature[i] = hash(numBloc, 1, 2, montant, ePublicKey)[i];
		}
		
		b.tx1.txi[1].nBloc = numBloc;
		b.tx1.txi[1].nTx = 1;
		b.tx1.txi[1].nUtxo = 2;
		for(int i = 0; i < 64 ; i ++)
		{
			b.tx1.txi[1].signature[i] = hash(numBloc, 1, 2, montant, ePublicKey)[i];
		}

		b.tx1.txi[2].nBloc = numBloc;
		b.tx1.txi[2].nTx = 1;
		b.tx1.txi[2].nUtxo = 2;
		for(int i = 0; i < 64 ; i ++)
		{
			b.tx1.txi[2].signature[i] = hash(numBloc, 1, 2, montant, ePublicKey)[i];
		}

		b.tx1.txi[3].nBloc = numBloc;
		b.tx1.txi[3].nTx = 1;
		b.tx1.txi[3].nUtxo = 2;
		for(int i = 0; i < 64 ; i ++)
		{
			b.tx1.txi[3].signature[i] = hash(numBloc, 1, 2, montant, ePublicKey)[i];
		}

		b.tx1.utxo[0].dest[0] = dPublicKey[0];
		b.tx1.utxo[0].dest[1] = dPublicKey[1];
		b.tx1.utxo[0].dest[2] = dPublicKey[2];
		b.tx1.utxo[0].dest[3] = dPublicKey[3];
		b.tx1.utxo[0].montant = montant;
		for(int i = 0; i<64 ; i++)
		{
			b.tx1.utxo[0].hash[i] = hash(numBloc, 1, 1, montant, dPublicKey)[i];
		}		

		b.tx1.utxo[1].dest[0] = ePublicKey[0];
		b.tx1.utxo[1].dest[1] = ePublicKey[1];
		b.tx1.utxo[1].dest[2] = ePublicKey[2];
		b.tx1.utxo[1].dest[3] = ePublicKey[3];
		b.tx1.utxo[1].montant = verifyAmount(ePublicKey) - montant;
		for(int i = 0; i<64 ; i++)
		{
			b.tx1.utxo[0].hash[i] = hash(numBloc, 1, 2, montant, ePublicKey)[i];
		}

		b.tx0.utxo[0].dest[0] = ePublicKey[0];
		b.tx0.utxo[0].dest[1] = ePublicKey[1];
		b.tx0.utxo[0].dest[2] = ePublicKey[2];
		b.tx0.utxo[0].dest[3] = ePublicKey[3];
		b.tx0.utxo[0].montant = 1;
		for(int i = 0; i<64 ; i++)
		{
			b.tx1.utxo[0].hash[i] = hash(numBloc, 1, 1, montant, ePublicKey)[i];
		}

		miner(b,b.tx1.utxo[0].hash);

		return true;
	}

	else
	{
		if(montant == 0)
		{
			std::cerr << "Transaction amount : Null value" << std::endl;
		}
		else if (montant < 0)
		{
			std::cerr << "Transaction amount : Negative value" << std::endl;
		}
		else
		{
			std::cerr << "the value you want to send is higher than what you have in your wallet" << std::endl;
		}
		return false;
	}

}