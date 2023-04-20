package tarefinha1;

import java.util.Set;

public class Animal {
	private String especie;
	private float peso;
	private String habittat;
	
	public Animal(String especie, float peso, String habittat) {
		this.especie = especie;
		if(peso >= 0) {
			this.peso = peso;
		}
		this.habittat = habittat;
	}
	
	/*faltam setters e getters*/
	
	public void correr() {
		System.out.println(especie + " está correndo");
	} 
	
	public void dormir() {
		System.out.println(especie + " está dormindo");
	}
	
	public void comer() {
		System.out.println(especie + " está correndo");
	}
}