package arquivoUsuario;

public class User {
	private String nomeCompleto;
	private String usuario;
	private String senha;
	
	public User(String nomeCompleto, String usuario, String senha) {
		this.nomeCompleto = nomeCompleto;
		this.usuario = usuario;
		this.senha = senha;
	}

	public String getNomeCompleto() {
		return nomeCompleto;
	}

	public String getUsuario() {
		return usuario;
	}
	
	public String codificarSenha(String senha) {
		return senha.concat("123");
	}
	
	public static String decodificarSenha(String codificada) {
		return codificada.substring(0, codificada.length() - 3);
	}
}
