# FDF - 42 Project
![FDF](https://github.com/user-attachments/assets/84cf8fa1-6fa4-437c-86bf-341a0e3bdec4)

## Descripción

FDF es un proyecto de la escuela 42 que consiste en crear una representación gráfica de un terreno en relieve. Utilizando un mapa 2D, el objetivo es visualizar un modelo de alambre en 3D.

## Características
- **Pintado de pantalla**: Uso de algoritmo de Bresenham, para el trazado de lineas.
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
    git clone https://github.com/E10YDEV/fdf.git
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

## Mapas
Los mapas son archivos con extensión .fdf que podrás encontrar en la ruta ./maps/*.fdf o poder crear el tuyo propio. 
```0 0 0 0 0
0 1 1 1 0
0 1 2 1 0
0 1 1 1 0
0 0 0 0 0 
```
Este archivo representa una matriz de puntos en un espacio 3D. Cada número en el archivo corresponde a la altura de ese punto en la matriz. Aquí hay una breve explicación de cómo interpretar este mapa:

- **0 0 0 0 0**: La primera fila tiene todos los puntos con altura 0, lo que significa que están al nivel del suelo.
- **0 1 1 1 0**: La segunda fila tiene tres puntos con altura 1 en el medio, formando una pequeña elevación.
- **0 1 2 1 0**: La tercera fila tiene un punto con altura 2 en el centro, creando un pico.
- **0 1 1 1 0**: La cuarta fila es similar a la segunda, con una pequeña elevación.
- **0 0 0 0 0**: La última fila tiene todos los puntos al nivel del suelo.

De forma opcional puedes añadir un color en hexadecima detrás de cada punto.
```
0,0x0000FF 0,0x0000FF 0,0x0000FF 0,0x0000FF 0,0x0000FF
0,0x0000FF 1,0x00FF00 1,0x00FF00 1,0x00FF00 0,0x0000FF
0,0x0000FF 1,0x00FF00 2,0xFF0000 1,0x00FF00 0,0x0000FF
0,0x0000FF 1,0x00FF00 1,0x00FF00 1,0x00FF00 0,0x0000FF
0,0x0000FF 0,0x0000FF 0,0x0000FF 0,0x0000FF 0,0x0000FF
```
Este archivo representa una matriz de puntos en un espacio 3D, donde cada punto tiene una altura y un color asociado. Aquí hay una breve explicación de cómo interpretar este mapa:

- **0,0x0000FF**: La primera fila tiene todos los puntos con altura 0 y color azul (0x0000FF).
- **0,0x0000FF 1,0x00FF00 1,0x00FF00 1,0x00FF00 0,0x0000FF**: La segunda fila tiene tres puntos con altura 1 y color verde (0x00FF00) en el medio, formando una pequeña elevación.
- **0,0x0000FF 1,0x00FF00 2,0xFF0000 1,0x00FF00 0,0x0000FF**: La tercera fila tiene un punto con altura 2 y color rojo (0xFF0000) en el centro, creando un pico.
- **0,0x0000FF 1,0x00FF00 1,0x00FF00 1,0x00FF00 0,0x0000FF**: La cuarta fila es similar a la segunda, con una pequeña elevación.
- **0,0x0000FF**: La última fila tiene todos los puntos con altura 0 y color azul.

## Capturas
![simplescreenrecorder-2025-03-21_18 06 54(2)](https://github.com/user-attachments/assets/50f36c5e-ad03-49b8-8864-ce41ef837e9a)
![image](https://github.com/user-attachments/assets/f20acbf7-2715-4066-a027-a94f252d195f)



 
## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo LICENSE para más detalles.

## Contacto

Para cualquier fallo o duda siente libre de abrir una ISSUE.
