# Informe. Primera Parte

**Alumno: ** César Alberto Mayora Suárez

**DNI:** Y5430138J

### Clase ConjuntoParticulas

La primera parte del proyecto se quería implementar un clase dónde se manipularán varias partículas contenidas en lo que será un conjunto de partículas.

En la implementación de ésta clase se prentendía la creación de un conjunto de objetos de la clase Partícula, con su respectiva capacidad (capacidad) y número de partículas (size). 

En los métodos de la clase se trata de cubrir cualquier manipulación de estas partículas. En general no hubo ningún problema, aunque hubo algunas dificultades en especial con la gestión de memoria dinámica en el método privado "resizeConjunto" donde se redimensiona en conjunto.

En la implementación de otros métodos como "reservaMemoria" y "liberaMemoria" se pasa como parámetro "Particula * &set", aunque es verdad que, como método de la clase, no es necesario pasar este parámetro, pero debido a que se también se manipulan conjuntos, como en la redimensión del conjunto, que no son del objeto en cuestión; se declara de esta manera para que sea más "general".

A *grosso modo* no hubo más dificultad de lo mencionado, pasando todos los test del fichero *pruebasConjunto.cpp*.

| TEST | COMPILA | EJECUTA | VALGRIND |
| ---- | ------- | ------- | -------- |
| t1   | SÍ      | SÍ      | BIEN     |
| t2   | SÍ      | SÍ      | BIEN     |
| t3   | SÍ      | SÍ      | BIEN     |
| t4   | SÍ      | SÍ      | BIEN     |
| t5   | SÍ      | SÍ      | BIEN     |

![](/home/cesar/Desktop/minijuego.jpg)

## Minijuego

Para la implementación del minijuego estudié los ejemplos dados por el profesorado en la página de PRADO, de manera que tenga una visión y guía breve y básica de las funciones de raylib como *InitWindow* o *DrawCircle*.

Para hacer el minijuego, se crea un fichero main con el nombre *capturaOvni.cpp* donde se implementará el *update* y el *draw* del minijuego mediante un bucle *while* que se detendrá cuando se presioné ESC o se cierre la ventana.

Se podrá ver en el fichero que creo dos variable *ticks* y *time* estas variables se usarán para medir el tiempo en segundos mientras se juega el minijuego. Debido a que el juego correrá a 60 FPS, pues *ticks* se incrementará en 1 en módulo 60, por tanto, *time* se incrementará en 1 cuando ticks sea igual a 0, así en el juego se contará en segundos el tiempo transcurrido.

Cuando termina el juego, es decir, cuando no hayan mas particulas se dejarán de actualizar los datos del conjunto y de la partícula base y se dibujará una pantalla en donde se mostrará el tiempo total que se ha jugado.

Más allá de lo dicho no hubo problema en la implementación del minijuego.

**Preguntas acerca de la implementación del juego:**

- La instalación de *raylib* me ha resultado: fácil.
- La programación de videojuego me ha resultado: fácil.
- Estoy conforme con el resultado final.
- Sería interesante guardar los datos como el tiempo transcurrido como un *score* del jugador. Se podría implementar una "base de datos" muy primitiva en un fichero de texto; y mediante la escritura de ficheros que provee C++ se podría actualizar el tiempo trancurrido si este es menor al que se lee en el fichero de texto. No me resultaría difícil implementarlo y se podría mejorar y desarrollar la idea.











