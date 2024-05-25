#pragma once

/**
 * @brief Clase que representa una bodega de alimentos.
 */
class BodegaAlimentos
{
public:
    int id; ///< Identificador de la bodega.
    int plantaId;  ///< Identificador de la planta a la que pertenece la bodega.

    /**
     * @brief Obtiene el identificador de la bodega.
     * @return El identificador de la bodega.
     */
    int get_id() const;

    /**
    * @brief Establece el identificador de la bodega.
    * @param id El nuevo identificador de la bodega.
    */
    void set_id(int id);

    /**
     * @brief Obtiene el identificador de la planta a la que pertenece la bodega.
     * @return El identificador de la planta.
     */
    int get_planta_id() const;

   /**
    * @brief Establece el identificador de la planta a la que pertenece la bodega.
    * @param planta_id El nuevo identificador de la planta.
    */
    void set_planta_id(int planta_id);
};
