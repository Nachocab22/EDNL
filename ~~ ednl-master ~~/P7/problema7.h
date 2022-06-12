//
//  problema7.h
//  P7
//
//  Created by JM on 16/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema7_h
#define problema7_h

typedef GrafoP<float>::vertice ciudad;

float Calcular_coste_viaje(const GrafoP<float> &tren, const GrafoP<float> &bus,
						   ciudad origen, ciudad destino, ciudad cambio1, ciudad cambio2,
						   Lista<ciudad> &ruta)
{
	float por_cambio1, por_cambio2, coste_min;
	vector<float> desde_origen, hasta_destino;
	vector<ciudad> caminos_desde_origen, caminos_hasta_destino;
	
	desde_origen = Dijkstra(tren, origen, caminos_desde_origen);
	hasta_destino = Dijkstra_inv(bus, destino, caminos_hasta_destino);
	
	por_cambio1 = suma(desde_origen[cambio1], hasta_destino[cambio1]);
	por_cambio2 = suma(desde_origen[cambio2], hasta_destino[cambio2]);
	
	if(por_cambio1 < por_cambio2)
	{
		ruta = camino<float>(origen, cambio1, caminos_desde_origen);
		ruta += camino<float>(destino, cambio1, caminos_hasta_destino);
		coste_min = por_cambio1;
	}
	else
	{
		ruta = camino<float>(origen, cambio2, caminos_desde_origen);
		ruta += camino<float>(destino, cambio2, caminos_hasta_destino);
		coste_min = por_cambio2;
	}
	
	return coste_min;
}

#endif /* problema7_h */
