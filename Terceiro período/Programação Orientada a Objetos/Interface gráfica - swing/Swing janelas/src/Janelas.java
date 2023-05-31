import java.awt.FlowLayout;
import java.io.File;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;

public class Janelas {
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				painelErro();
			}
		});
	}
	
	private static void abrirArquivo() {
		JFrame f = new JFrame("Arquivo");
		f.setLayout(new FlowLayout());
		f.setSize(500,500);
		
		JFileChooser chooser = new JFileChooser();
		FileNameExtensionFilter filter = new FileNameExtensionFilter("JPG & GIF Images", "jpg", "gif");
		
		chooser.setFileFilter(filter);
		
		int returnVal = chooser.showOpenDialog(f);
		if(returnVal == JFileChooser.APPROVE_OPTION) {
			File selectedFile = chooser.getSelectedFile();
			System.out.println("You chose: " + selectedFile.getName());
		}
		
		f.setVisible(true);
	}
	
	private static void salvarArquivo() {
		JFrame f = new JFrame("Arquivo");
		f.setLayout(new FlowLayout());
		f.setSize(500,500);
		
		JFileChooser chooser = new JFileChooser();

		int returnVal = chooser.showSaveDialog(f);
		if(returnVal == JFileChooser.APPROVE_OPTION) {
			File selectedFile = chooser.getSelectedFile();
			System.out.println("You chose to save this file as: " + selectedFile.getName());
		}
		
		f.setVisible(true);
	}
	
	//JOpctionPane para mostrar popup de mensagem, warning, caixa de diálogo para confirmação (sim, não ou cancela), leitura de informações do usuário (opção ou caixa de texto)
	private static void painelErro() {
		JFrame f = new JFrame("Arquivo");
		f.setLayout(new FlowLayout());
		f.setSize(500,500);
		
		JOptionPane.showMessageDialog(f,"Ocorreu um erro", "Erro", JOptionPane.PLAIN_MESSAGE);
		
		int opt = JOptionPane.showConfirmDialog(f, "Você entendeu?", "Atenção!", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
	}
}
