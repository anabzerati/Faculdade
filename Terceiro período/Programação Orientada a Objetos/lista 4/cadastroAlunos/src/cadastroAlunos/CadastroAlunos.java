package cadastroAlunos;

import java.util.ArrayList;
import java.util.Scanner;

public class CadastroAlunos {
	private ArrayList<Aluno> alunos = new ArrayList<>();
	
	public void adicionarAluno(Aluno aluno) {
		alunos.add(aluno);
	}

	public Aluno buscarAluno(String matricula) throws AlunoInexistenteException {
		for(Aluno a : alunos) {
			if(a.getMatricula().equals(matricula)) {
				return a;
			}
		}
		throw new AlunoInexistenteException("Matrícula não cadastrada");
	}
	
	public void removerAluno(String codigo) {
		try {
			Aluno remover = buscarAluno(codigo);
			alunos.remove(remover);
		} catch(AlunoInexistenteException e) {
			System.err.println(e.getMessage());
		}
	}
	
	public void listarAlunos() {
		System.out.println("Alunos: ");
		for(Aluno a : alunos) {
			System.out.printf("%s - %s - nota: \n", a.getNome(), a.getMatricula(), a.getNota());
		}
	}
	
	public void adicionarAlunoInterativo () {
		Scanner scanner = new Scanner(System .in) ;
		boolean adicionadoComSucesso = false ;
	
		while(!adicionadoComSucesso) {
			try {
				System.out.print("Digite o nome do aluno: ");
				String nome = scanner.nextLine();
		
				System.out.print("Digite a matricula do aluno : ");
				String matricula = scanner.nextLine();
				
				System.out.print(" Digite a nota do aluno : ");
				double nota = scanner.nextDouble ();
				scanner.nextLine(); 
		
				Aluno aluno = new Aluno(matricula, nome);
				aluno.setNota(nota);
				adicionarAluno(aluno);
				adicionadoComSucesso = true ;
				System.out.println("Aluno adicionado com sucesso!");
				
			} catch ( MatriculaInvalidaException e) {
				System.err.println(e. getMessage ());
				System.out.println("Por favor, insira os dados corretos.");
			}
		}
		
		scanner.close();
	}
	
}