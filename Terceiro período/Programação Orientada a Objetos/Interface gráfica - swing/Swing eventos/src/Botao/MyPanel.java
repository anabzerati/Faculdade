package Botao;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyPanel extends JPanel {
	JButton botaoVerde = new JButton("Verde");
	JButton botaoRosa = new JButton("Rosa");
	JButton botaoAzul = new JButton("Azul");

	public MyPanel() {
		this.add(botaoAzul);
		this.add(botaoRosa);
		this.add(botaoVerde);
		
		botaoVerde.addActionListener(e -> {
			setBackground(Color.GREEN);
		});
		
		//botaoVerde.addActionListener(new Listener()); -- duas opções
		botaoRosa.addActionListener(new Listener());
		botaoAzul.addActionListener(new Listener());
	}
	
	private class Listener implements ActionListener { //classe anônima para tratar
		@Override
		public void actionPerformed(ActionEvent e) {
			Object source = e.getSource();
			
			if(source == botaoRosa) {
				setBackground(Color.PINK);
			} else if(source == botaoAzul) {
				setBackground(Color.BLUE);
			} else if(source == botaoVerde) {
				setBackground(Color.GREEN);
			}
			
		}
	}
}
