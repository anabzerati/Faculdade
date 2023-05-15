package frequenciaPalavras;

import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

public class Main {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		SortedMap<String, Integer> sortedMap = new TreeMap<>();
		
		System.out.println("Insira texto: ");
		String texto = input.nextLine();
		
		String palavras[] = texto.split(" ");
		
		for(String atual : palavras) {
			atual = atual.toLowerCase();
			if(sortedMap.containsKey(atual)) {
				int quant = sortedMap.get(atual) + 1;
				sortedMap.put(atual, quant);
			} else {
				sortedMap.put(atual, 1);
			}
		}
		
		System.out.println("Quantidade das aparições: ");
		for (String palavra : sortedMap.keySet()) {
		    System.out.println(palavra + " - " + sortedMap.get(palavra));
		}
		
		input.close();
	}
	
}
