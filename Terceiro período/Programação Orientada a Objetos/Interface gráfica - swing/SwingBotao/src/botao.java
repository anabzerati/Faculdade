import java.awt.FlowLayout;
import java.awt.event.KeyEvent;

import javax.swing.AbstractButton;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.SwingUtilities;

import javax.swing.JFrame;
import javax.swing.ImageIcon;
import javax.swing.JRadioButton;
import javax.swing.ListSelectionModel;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JScrollPane;

public class botao {
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				listaPainel();
			}
		});
	}
	
	private static void createAndShowButton() {
		JFrame f = new JFrame("Swing botão");
		f.setLayout(new FlowLayout());
		f.setSize(500,500);
		
		ImageIcon teste = new ImageIcon("img/amor.jpg");
		
		JButton b1, b2, b3;
		
		b1 = new JButton("Disable middle button");
		b1.setVerticalTextPosition(AbstractButton.CENTER);
		b1.setHorizontalTextPosition(AbstractButton.LEADING);
		b1.setMnemonic(KeyEvent.VK_D);
		
		b2 = new JButton("MiddleButton");
		b2.setVerticalTextPosition(AbstractButton.BOTTOM);
		b2.setHorizontalTextPosition(AbstractButton.CENTER);
		b2.setMnemonic(KeyEvent.VK_M);
		
		b3 = new JButton("Enable Middle Button");
		b3.setMnemonic(KeyEvent.VK_E);
		b3.setEnabled(false);

		f.add(b1);
		f.add(b2);
		f.add(b3);
		
		f.setVisible(true); 
	}
	
	private static void amorEBibi() {
		JFrame f = new JFrame("Swing botão");
		f.setSize(500,500);
		
		f.setLayout(new FlowLayout());
		
		ImageIcon teste = new ImageIcon("img/amor.jpg");
		JLabel b = new JLabel(teste);
		
		JRadioButton amor = new JRadioButton("Amor");
		amor.setMnemonic(KeyEvent.VK_C);
		//amor.setSelected(true);
		
		JRadioButton bibi = new JRadioButton("Bibi");
		bibi.setMnemonic(KeyEvent.VK_C);
		
		JRadioButton amorBibi = new JRadioButton("Amor e Bibi");
		amorBibi.setMnemonic(KeyEvent.VK_C);
		amorBibi.setSelected(true);
		
		f.add(amor);
		f.add(bibi);
		f.add(amorBibi);
		f.add(b);
		
		f.setVisible(true);
		
		if(amor.isSelected())
			System.out.println("Amor está selecionado");
		else if (bibi.isSelected())
			System.out.println("Bibi selecionada");
		else if (amorBibi.isSelected())
			System.out.println("Amor e bibi selecionado");
		
	}
	
	private static void checkBox()
	{
		JFrame f = new JFrame("Swing checkbox");
		f.setSize(500,500);
		
		f.setLayout(new FlowLayout());
		
		ImageIcon teste = new ImageIcon("img/amor.jpg");
		JLabel b = new JLabel(teste);
		f.add(b);
		
		JCheckBox amorButton = new JCheckBox("Amor");
		amorButton.setMnemonic(KeyEvent.VK_C);
		
		JCheckBox bibiButton = new JCheckBox("Bibi");
		bibiButton.setMnemonic(KeyEvent.VK_C);
		
		f.add(amorButton);
		f.add(bibiButton);
		f.setVisible(true);
		
		
		String[] teste2 = {"um", "dois", "tres"};
		JComboBox testeCombo = new JComboBox(teste2);
		testeCombo.setSelectedIndex(1);
		
		f.add(testeCombo);
		
		//para ler estado
		String escolhido = (String)testeCombo.getSelectedItem();
		System.out.println(escolhido);
	}
	
	private static void listaPainel() {
		JFrame f = new JFrame("Swing checkbox");
		f.setSize(500,500);
		
		f.setLayout(new FlowLayout());
		
		DefaultListModel listModel = new DefaultListModel();
		
		listModel.addElement("Amor");
		listModel.addElement("Bibi");
		listModel.addElement("Amor e Bibi");
		listModel.addElement("Amor");
		listModel.addElement("Bibi");
		listModel.addElement("Amor e Bibi");
		listModel.addElement("Amor");
		listModel.addElement("Bibi");
		listModel.addElement("Amor e Bibi");
		
		
		JList list = new JList(listModel);
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		list.setLayoutOrientation(JList.VERTICAL_WRAP);
		
		f.add(list);
		
		JScrollPane scroll = new JScrollPane(list);
		f.add(scroll);
		
		//int index = list.getSelectedIndex();
		//listModel.remove(index);
		
		f.setVisible(true);
		
		System.out.println("List Size = " + listModel.getSize());
	}
}
