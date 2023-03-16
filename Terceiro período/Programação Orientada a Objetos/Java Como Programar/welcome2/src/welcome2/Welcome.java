package welcome2;

public class Welcome {
	private String name;
	
	public Welcome(String name){ //Constructor.Determina o nome na criação do objeto. 
		this.name = name;
	}
	
	public void setName(String name){ //muda nome do objeto
		this.name = name;
	}
	
	public String getName(){ //usado para referenciar nome do objeto em métodos de outras classes
		return name;
	}
	
	public void sayHello(){
		System.out.printf("Hello %s", getName());
	}
}
