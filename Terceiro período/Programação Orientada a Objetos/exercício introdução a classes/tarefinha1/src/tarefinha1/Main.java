package tarefinha1;

public class Main {

	public static void main(String[] args) {
		// aqui na main que faremos as associações entre homem, cachorro, casa e carro
		Animal tigre = new Animal("tigre", 100, "floresta"); 
		Cachorro dog = new Cachorro("belinha", 10, "casa", "vira-lata");
		Homem bibi = new Homem("bibi");
		Carro car = new Carro("Chevrolet", "Prisma", 2019, 10);
		Casa home = new Casa("rua", 4403);
		
		dog.setDono(bibi);
		car.setDono(bibi);
		home.setMorador(bibi);
		
		tigre.comer();
		dog.brincarComDono();
		bibi.dormir();
		car.acelerar();
		home.limparCasa();
		home.mudarDeCasa();
		home.getMorador();

	}

}
