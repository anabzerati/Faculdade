import javax.swing.SwingUtilities;
import javax.swing.JMenuBar;

import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;

import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;

public class Menu {
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {

			}
		});
	}
	
	private static void menu() {
		JMenuBar menuBar = new JMenuBar();
		
		JMenu menu1 = new JMenu("A menu");
		menu1.setMnemonic(KeyEvent.VK_A);
		
		menuBar.add(menu1);
		
		JMenuItem menuItem = new JMenuItem();
		menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_1, ActionEvent.ALT_MASK));
		menu1.add(menuItem);
		
		menuItem.setMnemonic(KeyEvent.VK_B);
		menu1.add(menuItem);
		
		menu1.addSeparator();
		
	}
}
