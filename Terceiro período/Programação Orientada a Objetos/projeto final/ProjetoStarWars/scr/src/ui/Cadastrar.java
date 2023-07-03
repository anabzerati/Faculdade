package ui;

import componentes.*;
import sun.security.provider.ConfigFile;
import ui.mapa.Tracker;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.geom.RoundRectangle2D;

/**
 * Tela de cadastro de objeto ao sistema. Apresenta opções de cadastro e campos específicos a partir da opção feita.
 */
public class Cadastrar extends JFrame {
    private CardLayout cardlayout = new CardLayout();
    JPanel cardPanel = new JPanel(cardlayout);
    private JLabel select = new JLabel("Selecione a opção: ");
    private String[] itens = {"Rebelde", "Patrulha", "Marcha",
            "Recebimento", "Combate", "Blitz"};

    private JComboBox<String> itensBox = new JComboBox<>(itens);

    public Cadastrar(Tracker tracker) throws HeadlessException {
        PanelFundo fundo = new PanelFundo();

        fundo.setVisible(true);
        fundo.setLayout(new BoxLayout(fundo, BoxLayout.Y_AXIS));
        add(fundo);

        inicializarTela();

        fundo.add(checkbox());

        cardPanel.setBorder(BorderFactory.createEmptyBorder(50, 0, 0, 0));
        cardPanel.setOpaque(false);
        itensBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if(e.getStateChange() == ItemEvent.SELECTED) {
                    String selecionado = (String) itensBox.getSelectedItem();
                    cardPanel.add(form(selecionado, tracker), selecionado);
                    cardlayout.show(cardPanel, selecionado);
                }
            }
        });

        fundo.add(cardPanel);
    }

    /**
     * Função para inializar a tela, segue o padrão das outras classes.
     */
    private void inicializarTela() {
        this.setSize(1200, 900);
        this.setLocationRelativeTo(null);
        setUndecorated(true);
        setShape(new RoundRectangle2D.Double(10, 10, getWidth(), getHeight(), 50, 50));
        setVisible(true);
    }

    /**
     * Estrutura básica do combobox tipo, que apresenta os tipos
     * @return
     */
    private JPanel checkbox() {
        JPanel botao = new JPanel(new FlowLayout());

        select.setLabelFor(itensBox);
        select.setForeground(Color.WHITE);

        itensBox.setSelectedItem(null);

        botao.add(select);
        botao.add(itensBox);
        botao.setVisible(true);
        botao.setSize(getWidth(), 300);
        botao.setOpaque(false); // deixa transparente

        // cria uma margem de 100 pixels. Como o tamanho de tela é fixa, não é necessário se preocupar com estar responsivo ou não.
        botao.setBorder(BorderFactory.createEmptyBorder(50, 0, 0, 0));
        return botao;
    }

    /**
     * Retorna um Jpanel com os campos específicos de cada classe. É chamado no acionListener do botão tipo.
     * @param selecionado
     * @param tracker
     * @return
     */
    private JPanel form(String selecionado, Tracker tracker) {
        SpinnerModel modelforX = new SpinnerNumberModel(0, 0, 1200, 1); //limita os valores de coordenada X e Y (do mapa)
        SpinnerModel modelforY = new SpinnerNumberModel(0, 0, 900, 1);

        JPanel returnedPanel = new JPanel(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.anchor = GridBagConstraints.WEST;
        constraints.insets = new Insets(10, 10, 5, 15); // Espaçamento interno

        JLabel label1 = new JLabel("Coordenada x: ");
        label1.setFont(new Font("Sans-serif", Font.PLAIN, 20));
        label1.setForeground(Color.WHITE);

        JSpinner coordenadaX = new JSpinner(modelforX);
        coordenadaX.setPreferredSize(new Dimension(200, 20));

        JLabel label2 = new JLabel("Coordenada y: ");
        label2.setFont(new Font("Sans-serif", Font.PLAIN, 20));
        label2.setForeground(Color.white);

        JSpinner coordenadaY = new JSpinner(modelforY);
        coordenadaY.setPreferredSize(new Dimension(200, 20));

        JLabel label3 = new JLabel("Descrição: ");
        label3.setForeground(Color.WHITE);
        label3.setFont(new Font("Sans-serif", Font.PLAIN, 20));

        JTextField descricao = new JTextField();
        descricao.setPreferredSize(new Dimension(200, 80));

        JLabel nums = new JLabel("Números: ");
        nums.setForeground(Color.WHITE);
        nums.setFont(new Font("Sans-serif", Font.PLAIN, 20));

        JSpinner numsSpinner = new JSpinner(new SpinnerNumberModel(0, 0, Integer.MAX_VALUE, 1));
        numsSpinner.setPreferredSize(new Dimension(200, 20));

        constraints.gridx = 0;
        constraints.gridy = 0;
        returnedPanel.add(label1, constraints);

        constraints.gridx = 1;
        returnedPanel.add(coordenadaX, constraints);

        constraints.gridx = 0;
        constraints.gridy = 1;
        returnedPanel.add(label2, constraints);

        constraints.gridx = 1;
        returnedPanel.add(coordenadaY, constraints);

        constraints.gridx = 0;
        constraints.gridy = 2;
        returnedPanel.add(label3, constraints);

        constraints.gridx = 1;
        constraints.gridy = 2;
        constraints.fill = GridBagConstraints.BOTH;
        returnedPanel.add(descricao, constraints);

        constraints.gridx = 0;
        constraints.gridy = 3;
        returnedPanel.add(nums, constraints);

        constraints.gridx = 1;
        constraints.gridy = 3;
        returnedPanel.add(numsSpinner, constraints);

        if (selecionado.equalsIgnoreCase("Rebelde")) {
            JButton okBtnRebelde = new JButton("Cadastrar");

            constraints.gridx = 1;
            constraints.gridy = 9;

            returnedPanel.add(okBtnRebelde, constraints);
            okBtnRebelde.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    Rebeldes cadastravel = new Rebeldes((Integer) coordenadaX.getValue(),
                            (Integer) coordenadaY.getValue(), descricao.getText(), (Integer)
                            numsSpinner.getValue());
                    tracker.cadastrar(cadastravel);

                    dispose();
                }
            });
        }
        if (!selecionado.equalsIgnoreCase("rebelde")) {
            JLabel label4 = new JLabel("Gravidade: ");
            label4.setForeground(Color.white);
            label4.setFont(new Font("Sans-serif", Font.PLAIN, 20));

            String[] gravidade = {"Ultra", "Alta", "Média", "Baixa"};
            JComboBox<String> comboBox = new JComboBox<>(gravidade);

            constraints.gridx = 0;
            constraints.gridy = 4;
            returnedPanel.add(label4, constraints);

            constraints.gridx = 1;
            constraints.gridy = 4;
            returnedPanel.add(comboBox, constraints);

            if (selecionado.equalsIgnoreCase("patrulha")) {
                JLabel label5 = new JLabel("Tipo: ");
                label5.setForeground(Color.WHITE);
                label5.setFont(new Font("Sans-serif", Font.PLAIN, 20));

                String[] tipo = {"Assalto", "Reconhecimento", "Desconhecido"};
                JComboBox<String> tipoBox = new JComboBox<>(tipo);

                constraints.gridx = 0;
                constraints.gridy = 5;
                returnedPanel.add(label5, constraints);

                constraints.gridx = 1;
                constraints.gridy = 5;
                returnedPanel.add(tipoBox, constraints);

                JButton okBtnPatrulha = new JButton("Cadastrar");

                constraints.gridx = 1;
                constraints.gridy = 9;
                returnedPanel.add(okBtnPatrulha, constraints);
                okBtnPatrulha.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        Patrulha cadastravel = new Patrulha((Integer) coordenadaX.getValue(), (Integer) coordenadaY.getValue(), descricao.getText(), (Integer) numsSpinner.getValue()
                                , (String) comboBox.getSelectedItem(), (String) tipoBox.getSelectedItem());
                        tracker.cadastrar(cadastravel);

                        dispose();
                    }
                });
            } else if (selecionado.equalsIgnoreCase("Combate")) {
                JLabel label5 = new JLabel("Quantidade de aliados: ");
                label5.setForeground(Color.WHITE);
                label5.setFont(new Font("Sans-serif", Font.PLAIN, 20));

                JSpinner aliados = new JSpinner(new SpinnerNumberModel(0, 0, Integer.MAX_VALUE, 1));

                JLabel label6 = new JLabel("Situação geral: ");
                label6.setForeground(Color.WHITE);
                label6.setFont(new Font("Sans-serif", Font.PLAIN, 20));

                JTextField situacao = new JTextField();

                constraints.gridx = 0;
                constraints.gridy = 5;
                returnedPanel.add(label5, constraints);

                constraints.gridx = 1;
                constraints.gridy = 5;
                returnedPanel.add(aliados, constraints);

                constraints.gridx = 0;
                constraints.gridy = 6;
                returnedPanel.add(label6, constraints);

                constraints.gridx = 1;
                constraints.gridy = 6;
                returnedPanel.add(situacao, constraints);

                JButton okBtnCombate = new JButton("Cadastrar");

                constraints.gridx = 1;
                constraints.gridy = 9;
                returnedPanel.add(okBtnCombate, constraints);
                okBtnCombate.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        Combate cadastravel = new Combate((Integer) coordenadaX.getValue(), (Integer) coordenadaY.getValue(), descricao.getText(), (Integer) numsSpinner.getValue()
                                , (String) comboBox.getSelectedItem(), (Integer) aliados.getValue(),
                                situacao.getText());
                        tracker.cadastrar(cadastravel);

                        dispose();
                    }
                });
            } else if (selecionado.equalsIgnoreCase("Marcha")) {
                JLabel label5 = new JLabel("Tamanho da marcha: ");
                label5.setForeground(Color.WHITE);
                label5.setFont(new Font("Sans-serif", Font.PLAIN, 20));

                JSpinner tamanhoFileira = new JSpinner(new SpinnerNumberModel(0, 0, Integer.MAX_VALUE, 1));

                constraints.gridx = 0;
                constraints.gridy = 5;
                returnedPanel.add(label5, constraints);

                constraints.gridx = 1;
                constraints.gridy = 5;
                returnedPanel.add(tamanhoFileira, constraints);

                JButton okbtn = new JButton("Cadastrar");

                constraints.gridx = 1;
                constraints.gridy = 9;
                returnedPanel.add(okbtn, constraints);

                okbtn.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        Marcha cadastravel = new Marcha((Integer) coordenadaX.getValue(), (Integer) coordenadaY.getValue(), descricao.getText(), (Integer) numsSpinner.getValue()
                                , (String) comboBox.getSelectedItem(), (Integer) tamanhoFileira.getValue());
                        tracker.cadastrar(cadastravel);

                        dispose();
                    }
                });
            } else if (selecionado.equalsIgnoreCase("Recebimento")) {
                JLabel label5 = new JLabel("Carga: ");
                label5.setFont(new Font("Sans-serif", Font.PLAIN, 20));
                label5.setForeground(Color.WHITE);

                JTextField carga = new JTextField();

                JLabel label6 = new JLabel("Peso (KG): ");
                label6.setForeground(Color.WHITE);
                label6.setFont(new Font("Sans-serif", Font.PLAIN, 20));

                JSpinner peso = new JSpinner(new SpinnerNumberModel(0, 0, Integer.MAX_VALUE, 1));

                constraints.gridx = 0;
                constraints.gridy = 5;
                returnedPanel.add(label5, constraints);

                constraints.gridx = 1;
                constraints.gridy = 5;
                returnedPanel.add(carga, constraints);

                constraints.gridx = 0;
                constraints.gridy = 6;
                returnedPanel.add(label6, constraints);

                constraints.gridx = 1;
                constraints.gridy = 6;
                returnedPanel.add(peso, constraints);

                JButton okbtnRecebimento = new JButton("Cadastrar");

                constraints.gridx = 1;
                constraints.gridy = 9;
                returnedPanel.add(okbtnRecebimento, constraints);
                okbtnRecebimento.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        Recebimento cadastravel = new Recebimento((Integer) coordenadaX.getValue(), (Integer) coordenadaY.getValue(), descricao.getText(), (Integer) numsSpinner.getValue()
                                , (String) comboBox.getSelectedItem(), carga.getText(), (Integer) peso.getValue());
                        tracker.cadastrar(cadastravel);

                        dispose();
                    }
                });
            } else {
                JLabel label5 = new JLabel("Veículos: ");
                label5.setForeground(Color.WHITE);
                label5.setFont(new Font("Sans-serif", Font.PLAIN, 20));

                JTextField veiculos = new JTextField();

                constraints.gridx = 0;
                constraints.gridy = 5;
                returnedPanel.add(label5, constraints);

                constraints.gridx = 1;
                constraints.gridy = 5;
                returnedPanel.add(veiculos, constraints);

                JButton okBtnBlitz = new JButton("Cadastrar");

                constraints.gridx = 1;
                constraints.gridy = 9;
                returnedPanel.add(okBtnBlitz, constraints);
                okBtnBlitz.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        Blitz cadastravel = new Blitz((Integer) coordenadaX.getValue(), (Integer) coordenadaY.getValue(), descricao.getText(), (Integer) numsSpinner.getValue()
                                , (String) comboBox.getSelectedItem(), veiculos.getText());
                        tracker.cadastrar(cadastravel);

                        dispose();
                    }
                });
            }

        }

        JButton cancel = new JButton("Voltar");

        constraints.gridx = 0;
        constraints.gridy = 9;
        returnedPanel.add(cancel, constraints);

        cancel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

        returnedPanel.setOpaque(false);

        return returnedPanel;
    }

}


