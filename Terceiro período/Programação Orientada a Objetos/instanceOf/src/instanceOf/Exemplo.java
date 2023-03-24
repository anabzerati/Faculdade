package instanceOf;

public class Exemplo {

	public static void main(String[] args) {
		Integer intObj = Integer.valueOf (123); //útil usar classes pelos métodos
		Long longObj = Long.valueOf(1234567890);
		Double doubleObj = Double.valueOf(12.345);
		Boolean boolObj = Boolean.valueOf(true);
		Object [] objArray = {intObj, longObj, doubleObj, boolObj};
		
		for (int i = 0; i < objArray.length ; i++) {
			if (objArray[i] instanceof Number) {
				System.out.println(objArray[i].toString() + " ́e um Number.");
			} else {
				System.out.println(objArray[i].toString() + " NÃO é um Number.");
			}
		}
	}
}

/*OBS: os objetos herdam de uma classe Object, sendo que há uma divisão lá, com tipos primitivos int float etc herdando
 * de uma subclasse Numbers e valores booleanos diretamente de Object.*/