//
//  problema10.h
//  P7
//
//  Created by JM on 31/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema10_h
#define problema10_h

typedef GrafoP<float>::vertice ciudad;
typedef enum{IZQUIERDA, CENTRO, DERECHA} Posicion;

template <typename T>
const T &min3(const T &a, const T &b, const T &c)
{
	return std::min(std::min(a, b), c);
}

Posicion Determinar_posicion(ciudad columna, size_t n)
{
	if(columna <= n-1)
		return IZQUIERDA;
	else if(columna <= 2*n-1)
		return CENTRO;
	else
		return DERECHA;
}

inline bool diagonal(ciudad i, ciudad j, size_t N)
{
	return i % N == j % N;
}

void Normalizar_ruta(Lista<ciudad> &Ruta, const size_t N)
{
	Lista<ciudad>::posicion p, siguiente;
	
	// Eliminar numeros inexistentes de ciudades (mayores que N)
	p = Ruta.primera();
	while(p != Ruta.fin())
	{
		Ruta.elemento(p) %= N;
		p = Ruta.siguiente(p);
	}
	
	// Eliminar repetidos (trasbordos)
	p = Ruta.primera();
	siguiente = Ruta.siguiente(p);
	while(Ruta.siguiente(p) != Ruta.fin())
	{
		if(Ruta.elemento(p) == Ruta.elemento(siguiente))
			Ruta.eliminar(siguiente);
		p = Ruta.siguiente(p);
		siguiente = Ruta.siguiente(p);
	}
}

GrafoP<float> Combinar_costes(const GrafoP<float> &bus, const GrafoP<float> &tren,
							  const GrafoP<float> &avion, float trasbordo_terrestre,
							  float trasbordo_avion)
{
	size_t n;
	ciudad i, j;
	
	n = bus.numVert();
	GrafoP<float> combinados(3*n);
	
	for(i = 0; i <= n-1; i++)		// Primeros tres cuadrantes: bus
		for(j = 0; j <= 3*n-1; j++)
			switch(Determinar_posicion(j, n))
			{
				case IZQUIERDA:		// Cuadrante primero: bus-bus
					if(diagonal(i, j, n))
						combinados[i][j] = 0;
					else
						combinados[i][j] = bus[i][j];
					break;
				case CENTRO:		// Cuadrante segundo: bus-tren
					if(diagonal(i, j, n))
						combinados[i][j] = trasbordo_terrestre;
					else
						combinados[i][j] = GrafoP<float>::INFINITO;
					break;
				case DERECHA:		// Cuadrante tercero: bus-avion
					if(diagonal(i, j, n))
						combinados[i][j] = trasbordo_avion;
					else
						combinados[i][j] = GrafoP<float>::INFINITO;
			}
	
	for(i = n; i <= 2*n-1; i++)		// Siguientes tres cuadrantes: tren
		for(j = 0; j <= 2*n-1; j++)
			switch(Determinar_posicion(j, n))
			{
				case IZQUIERDA:		// Cuadrante cuarto: tren-bus
					if(diagonal(i, j, n))
						combinados[i][j] = trasbordo_terrestre;
					else
						combinados[i][j] = GrafoP<float>::INFINITO;
					break;
				case CENTRO:		// Cuadrante quinto: tren-tren
					if(diagonal(i, j, n))
						combinados[i][j] = 0;
					else
						combinados[i][j] = tren[i-n][j-n];
					break;
				case DERECHA:		// Cuadrante sexto: tren-avion
					if(diagonal(i, j, n))
						combinados[i][j] = trasbordo_avion;
					else
						combinados[i][j] = GrafoP<float>::INFINITO;
					break;
			}
	
	for(i = 2*n; i <= 3*n-1; i++)	// Últimos tres cuadrantes: avion
		for(j = 0; j <= 3*n-1; j++)
			switch(Determinar_posicion(j, n))
			{
				case IZQUIERDA:		// Cuadrante séptimo: avion-bus
					if(diagonal(i, j, n))
						combinados[i][j] = trasbordo_avion;
					else
						combinados[i][j] = GrafoP<float>::INFINITO;
					break;
				case CENTRO:		// Cuadrante octavo: avion-tren
					if(diagonal(i, j, n))
						combinados[i][j] = trasbordo_avion;
					else
						combinados[i][j] = GrafoP<float>::INFINITO;
					break;
				case DERECHA:		// Cuadrante noveno: avion-avion
					if(diagonal(i, j, n))
						combinados[i][j] = 0;
					else
						combinados[i][j] = avion[i-2*n][j-2*n];
					break;
			}
	
	return combinados;
}


float Calcular_viaje(const GrafoP<float> &bus, const GrafoP<float> &tren,
					 const GrafoP<float> &avion, float trasbordo_terrestre, float trasbordo_avion,
					 ciudad origen1, ciudad destino1, Lista<ciudad> &Ruta)
{
	float min;
	size_t n;
	ciudad origen2, origen3, destino2, destino3;
	vector<float> costes1, costes2, costes3;
	vector<ciudad> caminos1, caminos2, caminos3;
	
	n = bus.numVert();
	origen2 = origen1 + n;
	origen3 = origen2 + n;
	destino2 = destino1 + n;
	destino3 = destino2 + n;
	
	GrafoP<float> combinados = Combinar_costes(bus, tren, avion, trasbordo_terrestre,
											   trasbordo_avion);
	
	costes1 = Dijkstra(combinados, origen1, caminos1);
	costes2 = Dijkstra(combinados, origen2, caminos2);
	costes3 = Dijkstra(combinados, origen3, caminos3);
	
	min = min3(min3(costes1[destino1], costes1[destino2], costes1[destino3]),
			   min3(costes2[destino1], costes2[destino2], costes2[destino3]),
			   min3(costes3[destino1], costes3[destino2], costes3[destino3]));
	
	// Construir la ruta
	if(min == costes1[destino1])
		Ruta = camino<float>(origen1, destino1, caminos1);
	else if(min == costes1[destino2])
		Ruta = camino<float>(origen1, destino2, caminos1);
	else if(min == costes1[destino3])
		Ruta = camino<float>(origen1, destino3, caminos1);
	else if(min == costes2[destino1])
		Ruta = camino<float>(origen2, destino1, caminos2);
	else if(min == costes2[destino2])
		Ruta = camino<float>(origen2, destino2, caminos2);
	else if(min == costes2[destino3])
		Ruta = camino<float>(origen2, destino3, caminos2);
	else if(min == costes3[destino1])
		Ruta = camino<float>(origen3, destino1, caminos3);
	else if(min == costes3[destino2])
		Ruta = camino<float>(origen3, destino2, caminos3);
	else if(min == costes3[destino3])
		Ruta = camino<float>(origen3, destino3, caminos3);
	
	Normalizar_ruta(Ruta, n);
	
	return min;
}

#endif /* problema10_h */
