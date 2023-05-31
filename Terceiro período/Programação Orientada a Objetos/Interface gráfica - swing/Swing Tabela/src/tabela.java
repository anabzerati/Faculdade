import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.JTable;
import javax.swing.JScrollPane;
import javax.swing.JPanel;

public class tabela {
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				criaTabela();
			}
		});
	}
	
	private static void criaTabela() {
		JFrame f = new JFrame("Swing botão");
		f.setLayout(new FlowLayout());
		f.setSize(500,500);
		
		String[] colunas = {"Nome", "Cargo", "Vegteriano"};
		
		Object[][] dados = {
				{"William", "Amor", false},
				{"Ana Beatriz", "Bibi", true}
		};
		
		JTable tabela = new JTable(dados, colunas);
		tabela.setPreferredScrollableViewportSize(new Dimension(500, 30));
		tabela.setFillsViewportHeight(true);
		
		JScrollPane scroll = new JScrollPane(tabela);
		
		//f.add(scroll);
		//f.add(tabela);
		f.setVisible(true);
		
		JPanel painel = new JPanel();
		painel.setBackground(Color.pink);
		painel.setPreferredSize(new Dimension(1000, 500));

		painel.add(scroll);
		f.add(painel);

	}
}
