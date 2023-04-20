package zoologico;

public class Zoologico {

	public static void main(String[] args) {
		Vaca vaca = new Vaca("Mimosa", 4);
		Ovelha ovelha = new Ovelha("Dooly", 4);
		Gato gato = new Gato("garfield", 4);
		
		Animal animais[] = {vaca, ovelha, gato};
		
		if(vaca instanceof Animal) {
			System.out.println("Vaca é animal");
		}
		if(ovelha instanceof Animal) {
			System.out.println("Ovelha é animal");
		}
		if(gato instanceof Animal) {
			System.out.println("Gato é animal");
		}
		
		for(int i = 0; i < animais.length; i++) {
			System.out.printf("%s", animais[i].getNome());
			if(animais[i] instanceof Vaca) {
				System.out.printf(" é vaca");
			} 
			if(animais[i] instanceof Ovelha) {
				System.out.printf(" é ovelha");
			}
			if(animais[i] instanceof Gato) {
				System.out.printf(" é gato");
			}
			
			System.out.printf(" e tem %d patas\n", animais[i].getNumeroPatas());
		}
		
	}

}
