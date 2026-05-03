import java.io.File;
import java.util.Scanner;

public class Productos {
    public static void main(String[] args) throws Exception {

        File archivo = new File("productos.txt");

        if (!archivo.exists()) {
            System.out.println("Error: archivo no existe");
            return;
        }

        Scanner sc = new Scanner(archivo);

        String nombre, mayorProducto = "";
        double precio, subtotal, total = 0, mayor = 0;
        int cantidad;

        while (sc.hasNext()) {
            nombre = sc.next();
            precio = sc.nextDouble();
            cantidad = sc.nextInt();

            subtotal = precio * cantidad;

            System.out.println("Producto: " + nombre);
            System.out.println("Subtotal: " + subtotal);
            System.out.println("----------------------");

            total += subtotal;

            if (subtotal > mayor) {
                mayor = subtotal;
                mayorProducto = nombre;
            }
        }

        System.out.println("TOTAL: " + total);
        System.out.println("Producto mayor: " + mayorProducto + " (" + mayor + ")");

        sc.close();
    }
}