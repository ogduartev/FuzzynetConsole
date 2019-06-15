#include <stdio.h>
#include <iostream>
using namespace std;

#include "wx/wx.h"

#include "proyecto.h"

int main()
{
	Proyecto proyecto;
	proyecto.iniciar(0);

	wxString ArchivoTmp="/home/ogduartev/Escritorio/DSMtest.fzn";
	Mi_ifpstream FileProy(ArchivoTmp);
	if(!proyecto.read(FileProy))
	{
	  cout << "NO" << endl;
	}else
	{
	  cout << "SI" << endl;
	}

	wxString ArchivoActual="/home/ogduartev/Escritorio/Exportar.txt";
	ListaSelecciones ListaSel;
  char Separador='\t';
  proyecto.importar(ArchivoActual,ListaSel,Separador);

  NumeroDifuso* resultado;
  double valor;

  proyecto.calcularTodo();
  resultado=proyecto.Estrategias.Item(0).calcular(&proyecto.Casos.Item(1));

  valor=resultado->valorRepresentativo(0.5,1);
  cout << valor << endl;

	return 0;
}
