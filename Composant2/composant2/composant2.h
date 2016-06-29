#include "stdafx.h"
#include "bloc.h"
#include <stdlib.h> 
#include <iostream> 
#include <vector>

std::vector<UTXO> getUTXO(Bloc b);
std::vector<UTXO> getAllUTXO(std::vector<Bloc> vb);
float verifyAmount(unsigned char key[4]);
bool createTransaction(unsigned char ePrivateKey[4], unsigned char ePublicKey[4], unsigned char dPublicKey[4], float montant);
int getNbBlocMax(std::vector<Bloc> vb);