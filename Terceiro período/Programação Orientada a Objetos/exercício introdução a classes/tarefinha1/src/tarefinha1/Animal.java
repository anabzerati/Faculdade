package tarefinha1;

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
		
	} 
	
	public void dormir() {
		
	}
	
	public void comer() {
		
	}
}