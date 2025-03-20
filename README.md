# FDF - 42 Project
![FDF](https://github.com/user-attachments/assets/84cf8fa1-6fa4-437c-86bf-341a0e3bdec4)

## Descripción

FDF es un proyecto de la escuela 42 que consiste en crear una representación gráfica de un terreno en relieve. Utilizando un mapa 2D, el objetivo es visualizar un modelo de alambre en 3D.

## Características

- **Movimiento y rotación**: Permite mover y rotar el modelo para una mejor visualización.
- **Elevación y zoom**: Gestión dinámica de la elevación y el zoom.
- **Gestión de colores**: Posibilidad de parsear los colores introducidos en el mapa.
- **Recorte de líneas**: Gestión de líneas para evitar artefactos visuales.

## Requisitos

- **Lenguaje**: C
- **Biblioteca gráfica**: MiniLibX (CODAM) se descargará del respositorio oficial cuando compiles.

## Instalación
 
1. Clona el repositorio:
    ```bash
    git clone https://github.com/tu_usuario/fdf.git
    ```
2. Navega al directorio del proyecto:
    ```bash
    cd FDF
    ```
3. Compila el proyecto:
    ```bash
    make
    ```

## Uso
> [!TIP]
> Puedes encontrar mapas de ejemplo en la ruta ./maps/ .
>
1. Ejecuta el programa:
    ```bash
    ./fdf mapa.fdf
    ```
2. Utiliza las teclas de dirección para mover el modelo.
3. Usa el ratón para zoom.

### Atajos de Teclado

- **Salir**: `Esc`
- **Aumentar o reducir Z factor**: `Up` o `Down`
- **Zoom**: `Rueda ratón`
- **Rotar**: `Left`,`Right`
- **Centrar**: `W` , `A` , `S` , `D`

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo LICENSE para más detalles.

## Contacto

Para cualquier fallo o duda siente libre de abrir una ISSUE.
