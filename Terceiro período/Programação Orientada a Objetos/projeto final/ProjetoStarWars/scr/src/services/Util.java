package services;

import ui.mapa.Tracker;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

/**
 * Classe final responsável por fornecer utilidades ao sistema.
 */
public final class Util {

    /**
     * Método responsável por ler o arquivo, a fim de logar no sistema os componentes já cadastrados.
     * É chamado no login, quando o usuário é aceito, antes de se iniciar o uso do sistema propriamente.
     * @return Tracker com os componentes cadastrados
     */
    public static Tracker readFile()
    {
        Tracker returnedTracker = new Tracker();
        try {
            FileInputStream inputStream = new FileInputStream("files/tracker.ser");
            ObjectInputStream objectInputStream = new ObjectInputStream(inputStream);
            Object tracker = objectInputStream.readObject();

            if(tracker != null)
                returnedTracker = (Tracker) tracker;

            objectInputStream.close();
            inputStream.close();

        } catch (FileNotFoundException e) {
           // throw new RuntimeException(e);
        } catch (IOException e) {
           // throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
        //    throw new RuntimeException(e);
        }

        return returnedTracker;
    }

    /**
     * Método responsável por escrever no arquivo as informações dos objetos, salvando-os.
     * É chamado quando o usuário fecha o sistema, garantindo que não haverá a possibilidade de cadastrar dados que não serão salvos.
     * @param tracker objeto a ser armazenado.
     */
    public static void writeFile(Tracker tracker)
    {
        try {
            FileOutputStream fileOutputStream = new FileOutputStream("files/tracker.ser");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(tracker);
            objectOutputStream.close();
            fileOutputStream.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    /**
     * Lê o arquivo de senha e retorna para que a tela de ui.Login possa encriptografar.
     * @return String senha lida do arquivo.
     */
    public static String readPassword() {
        try {
            FileReader fileReader = new FileReader("files/passwd.txt");
            Scanner reader = new Scanner(fileReader);

            return reader.nextLine();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
