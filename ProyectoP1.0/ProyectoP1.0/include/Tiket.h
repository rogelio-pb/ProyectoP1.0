#pragma once
#include "Prerequisites.h"



class Ticket {// Clase Ticket para representar un ticket individual
private:// Atributos privados
	int ID;// ID único del ticket
	std::string titulo;// Título del ticket
	std::string descripcion;// Descripción del ticket
    std::string estado; // Pendiente, En Proceso, Completado
	std::string fechaC;// Fecha de creación del ticket

public:// Métodos públicos

	Ticket// Constructor con fecha opcional
	(int id, const std::string& title, const std::string& desc,// Constructor del ticket que inicializa los atributos
		ESTADO est = PENDIENTE, const std::string& fecha = "")// Parámetros: ID, título, descripción, estado (por defecto PENDIENTE), fecha (por defecto cadena vacía)
		: ID(id), titulo(title), descripcion(desc) {// Inicialización de ID, título y descripción
		fechaC = fecha.empty() ? "Fecha no asignada" : fecha;// Si no se proporciona fecha, asignar "Fecha no asignada"
		switch (est) {// Asignar estado basado en el valor del enum ESTADO
		case PENDIENTE: estado = "Pendiente"; break;// Estado pendiente
		case EN_PROCESO: estado = "En Proceso"; break;// Estado en proceso
		case COMPLETADO: estado = "Completado"; break;// Estado completado
        }
    }

	int getID() const { return ID; }// Obtener el ID del ticket
	std::string getTitulo() const { return titulo; }// Obtener el título del ticket
	std::string getDescripcion() const { return descripcion; }// Obtener la descripción del ticket
	std::string getEstado() const { return estado; }// Obtener el estado del ticket
	std::string getFecha() const { return fechaC; }// Obtener la fecha de creación del ticket

	void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }// Cambiar el título del ticket en el gestor en el método editarTicket
	void setDescripcion(const std::string& nuevaD) { descripcion = nuevaD; }// Cambiar la descripción del ticket en el gestor en el método editarTicket


	bool cambioEstado(ESTADO nuevoEstado) {// Cambiar el estado del ticket con validación de transición
		if (nuevoEstado == PENDIENTE) {// Permitir volver a Pendiente desde cualquier estado
			estado = "Pendiente"; return true;// Cambiar a Pendiente
        }
		else if (nuevoEstado == EN_PROCESO && estado == "Pendiente") {// Permitir cambiar a En Proceso solo desde Pendiente
			estado = "En Proceso"; return true;// Cambiar a En Proceso
        }
		else if (nuevoEstado == COMPLETADO && estado == "En Proceso") {// Permitir cambiar a Completado solo desde En Proceso
			estado = "Completado"; return true;// Cambiar a Completado
        }
		std::cout << "Transicion de estado no valida.\n";// Mensaje de error si la transición no es válida
		return false;// Retornar falso si la transición no es válida
    }

	void mostrar() const {// Mostrar los detalles del ticket
		std::cout << "ID: " << ID// Mostrar el ID del ticket llenado en el gestor
			<< "  Titulo: " << titulo// Mostrar el título del ticket llenado en el gestor
			<< "  Descripcion: " << descripcion// Mostrar la descripción del ticket llenado en el gestor
			<< "  Estado: " << estado// Mostrar el estado del ticket llenado en el gestor
			<< "  Fecha: " << fechaC << std::endl;// Mostrar la fecha de creación del ticket
	}// Fin del método mostrar
};// Fin de la clase Ticket
