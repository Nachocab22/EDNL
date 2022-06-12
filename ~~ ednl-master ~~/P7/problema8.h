//
//  problema8.h
//  P7
//
//  Created by JM on 16/08/2020.
//  Copyright © 2020 JM Heredia. All rights reserved.
//

#ifndef problema8_h
#define problema8_h

typedef GrafoP<float>::vertice ciudad;

float Calcular_coste_viaje(const GrafoP<float> &tren, const GrafoP<float> &bus,
						   ciudad origen, ciudad destino, Lista<ciudad> &ruta)
{
	float coste_min, aux1, aux2;
	vector<float> origen_bus, origen_tren, destino_bus, destino_tren;
	vector<ciudad> caminos_obus, caminos_otren, caminos_dbus, caminos_dtren;
	ciudad i;
	size_t n;
	
	origen_bus = Dijkstra(bus, origen, caminos_obus);
	origen_tren = Dijkstra(tren, origen, caminos_otren);
	destino_bus = Dijkstra_inv(bus, destino, caminos_dbus);
	destino_tren = Dijkstra_inv(tren, destino, caminos_otren);
	
	coste_min = GrafoP<float>::INFINITO;
	
	aux1 = origen_bus[destino];
	if(aux1 < coste_min)
	{
		coste_min = aux1;
		ruta = camino<float>(origen, destino, caminos_obus);
	}
	
	aux1 = origen_tren[destino];
	if(aux1 < coste_min)
	{
		coste_min = aux1;
		ruta = camino<float>(origen, destino, caminos_otren);
	}
	
	n = tren.numVert();
	for(i = 0; i <= n-1; i++)
	{
		aux1 = suma(origen_bus[i], destino_tren[i]);
		aux2 = suma(origen_tren[i], destino_bus[i]);
		if(aux1 < coste_min && aux1 < aux2)
		{
			
		}
		else if(aux2 < coste_min)
		{
			
		}
	}
		
	return std::min(std::min(origen_bus[destino], origen_tren[destino]), coste_min);
}

#endif /* problema8_h */
