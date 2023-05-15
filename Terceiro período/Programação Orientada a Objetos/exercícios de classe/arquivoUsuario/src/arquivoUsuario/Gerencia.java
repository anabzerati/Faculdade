package arquivoUsuario;

import java.io.Console;
import java.util.Scanner;

public class Gerencia {
	private User userLogado;
	private Arquivo leitura;
	
	public Gerencia() {
		userLogado = null;
		leitura = new Arquivo();
	}
	
	public User getUsuarioLogado() {
		return userLogado;
	}
	
	public void cadastrarUsuario(String nomeCompleto, String senha, String usuario) throws SenhaInvalidaException {
		if(senha.length() < 5) {
			throw new SenhaInvalidaException("muito curta");
		}
		userLogado = new User(nomeCompleto, usuario, senha);
	}
	
	public void logar(String user, String senha) throws LoginException {
		Scanner input = new Scanner(System.in);
		int op;
		do {
			System.out.println("Deseja leitura dos dados por arquivo de texto (1) ou de objetos (2)? ");
			op = input.nextInt();
		} while(op != 1 && op !=2);
		
		if(op == 1) {
			String linha = leitura.lerArquivo(user);
			
			if(linha.equals("null")) {
				throw new LoginException("Falha no login");
			}
			
			String campos[] = linha.split(" ");
			String descriptografada = User.decodificarSenha(campos[1]);
			
			if(descriptografada.equals(senha)){
				System.out.println("Sucesso em logar!");
				
				User novo = new User(campos[2], campos[0], campos[1]);
				userLogado = novo;
			} else {
				throw new LoginException("Falha no login");
			}
		} else {
			userLogado = leitura.lerArquivoObj(user);
			
			if(userLogado == null) {
				throw new LoginException("Falha no login");
			} else {
				System.out.println("Sucesso em logar!");
			}
		}
		
	}
	
	public void telaInicial() {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Usuário: ");
		String user = input.nextLine();
		
		System.out.println("Senha: ");
		Console c = System.console();
		char[] senha = c.readPassword();
		
		try {
			logar(user, senha.toString());
		} catch (LoginException e) {
			System.err.println(e.getMessage());
		}
	}
}
