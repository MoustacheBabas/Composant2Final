#include "stdafx.h"
#include "bloc.h"
#include <stdlib.h> 
#include <iostream> 
#include <vector>

std::vector<Bloc> getBlocs() // on simule la fonction de composant 1 et on renvoie une liste de blocs dans un vector pour que notre composant puisse travailler
{
	Bloc a;
	Bloc b;
	Bloc c;

	a.num = 1;
	a.tx1.utxo[0].montant = 4;
	a.tx1.utxo[1].montant = 3;
	a.tx1.utxo[0].dest[0] = 'a';
	a.tx1.utxo[0].dest[1] = 'a';
	a.tx1.utxo[0].dest[2] = 'a';
	a.tx1.utxo[0].dest[3] = 'a';

	b.num = 2;
	b.tx1.utxo[0].montant = 5;
	b.tx1.utxo[1].montant = 6;
	b.tx1.utxo[0].dest[0] = 'a';
	b.tx1.utxo[0].dest[1] = 'a';
	b.tx1.utxo[0].dest[2] = 'a';
	b.tx1.utxo[0].dest[3] = 'a';
	
	c.num = 3;
	c.tx1.utxo[0].montant = 1;
	c.tx1.utxo[1].montant = 2;

	std::vector<Bloc> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	return v;
}