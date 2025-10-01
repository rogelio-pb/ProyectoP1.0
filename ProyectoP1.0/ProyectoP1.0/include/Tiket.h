#pragma once
#include "Prerequisites.h"



class Ticket {// Clase Ticket para representar un ticket individual
private:// Atributos privados
	int ID;// ID �nico del ticket
	std::string titulo;// T�tulo del ticket
	std::string descripcion;// Descripci�n del ticket
    std::string estado; // Pendiente, En Proceso, Completado
	std::string fechaC;// Fecha de creaci�n del ticket

public:// M�todos p�blicos

	Ticket// Constructor con fecha opcional
	(int id, const std::string& title, const std::string& desc,// Constructor del ticket que inicializa los atributos
		ESTADO est = PENDIENTE, const std::string& fecha = "")// Par�metros: ID, t�tulo, descripci�n, estado (por defecto PENDIENTE), fecha (por defecto cadena vac�a)
		: ID(id), titulo(title), descripcion(desc) {// Inicializaci�n de ID, t�tulo y descripci�n
		fechaC = fecha.empty() ? "Fecha no asignada" : fecha;// Si no se proporciona fecha, asignar "Fecha no asignada"
		switch (est) {// Asignar estado basado en el valor del enum ESTADO
		case PENDIENTE: estado = "Pendiente"; break;// Estado pendiente
		case EN_PROCESO: estado = "En Proceso"; break;// Estado en proceso
		case COMPLETADO: estado = "Completado"; break;// Estado completado
        }
    }

	int getID() const { return ID; }// Obtener el ID del ticket
	std::string getTitulo() const { return titulo; }// Obtener el t�tulo del ticket
	std::string getDescripcion() const { return descripcion; }// Obtener la descripci�n del ticket
	std::string getEstado() const { return estado; }// Obtener el estado del ticket
	std::string getFecha() const { return fechaC; }// Obtener la fecha de creaci�n del ticket

	void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }// Cambiar el t�tulo del ticket en el gestor en el m�todo editarTicket
	void setDescripcion(const std::string& nuevaD) { descripcion = nuevaD; }// Cambiar la descripci�n del ticket en el gestor en el m�todo editarTicket


	bool cambioEstado(ESTADO nuevoEstado) {// Cambiar el estado del ticket con validaci�n de transici�n
		if (nuevoEstado == PENDIENTE) {// Permitir volver a Pendiente desde cualquier estado
			estado = "Pendiente"; return true;// Cambiar a Pendiente
        }
		else if (nuevoEstado == EN_PROCESO && estado == "Pendiente") {// Permitir cambiar a En Proceso solo desde Pendiente
			estado = "En Proceso"; return true;// Cambiar a En Proceso
        }
		else if (nuevoEstado == COMPLETADO && estado == "En Proceso") {// Permitir cambiar a Completado solo desde En Proceso
			estado = "Completado"; return true;// Cambiar a Completado
        }
		std::cout << "Transicion de estado no valida.\n";// Mensaje de error si la transici�n no es v�lida
		return false;// Retornar falso si la transici�n no es v�lida
    }

	void mostrar() const {// Mostrar los detalles del ticket
		std::cout << "ID: " << ID// Mostrar el ID del ticket llenado en el gestor
			<< "  Titulo: " << titulo// Mostrar el t�tulo del ticket llenado en el gestor
			<< "  Descripcion: " << descripcion// Mostrar la descripci�n del ticket llenado en el gestor
			<< "  Estado: " << estado// Mostrar el estado del ticket llenado en el gestor
			<< "  Fecha: " << fechaC << std::endl;// Mostrar la fecha de creaci�n del ticket
	}// Fin del m�todo mostrar
};// Fin de la clase Ticket
