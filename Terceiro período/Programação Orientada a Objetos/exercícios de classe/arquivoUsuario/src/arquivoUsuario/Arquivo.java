 package arquivoUsuario;

import java.io.*;
import java.util.Scanner;

public class Arquivo {
	private FileReader arquivo;
	private ObjectInputStream in;
	
	public Arquivo() {
		try {
			arquivo = new FileReader("users.txt");
			in = new ObjectInputStream(new FileInputStream("users.dat"));
		} catch(FileNotFoundException e) {
			System.err.println("Erro: " +  e.getMessage());
		} catch(IOException e) {
			System.err.println("Erro: " + e.getMessage());
		}
	}
	
	public String lerArquivo(String user) {
		Scanner s = new Scanner(new BufferedReader(arquivo));
		
		while(s.hasNextLine()) {
			String linha = s.nextLine();
			String[] campos = linha.split(" ");
			if(campos[0].equalsIgnoreCase(user)) {
				return linha;
			}
		}
		return "null";
	}
	
	public User lerArquivoObj(String user) {
		try {
			User teste = (User) in.readObject();
			while(in.readObject() != null) {
				if(teste.getUsuario().equals(user)) {
					return teste;
				}				
				teste = (User) in.readObject();
			}
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return null;
	}
}
