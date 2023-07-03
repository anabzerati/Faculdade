package ui;

import componentes.*;
import ui.mapa.Marker;
import ui.mapa.Tracker;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.Area;
import java.awt.geom.RoundRectangle2D;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.ArrayList;
import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

/**
 * Tela que lista todos os itens mapeáveis que estão cadastrados. Para isso, cria, posiciona e dimensiona o frame, adiciona o fundo e, percorrendo a lista de cadastrados, adiciona um painel (JPanel) para cada.
 */
public class ListarInformacoes extends JFrame {
    PanelFundo fundo;

    /**
     * Construtor da classe. Cria, posiciona e dimensiona o frame. Adiciona o botão para voltar para a tela inicial. Chama o método que cria os paineis para cadastrados.
     * @param tracker - referência à <code>Tracker</code>, gerenciador do mapa.
     * */
    public ListarInformacoes(Tracker tracker) throws HeadlessException{
        this.setSize(1200, 900);
        this.setLocationRelativeTo(null);
        this.setBackground(Color.black);
        this.setUndecorated(true);
        this.setShape(new RoundRectangle2D.Double(10, 10, getWidth(),getHeight(), 50, 50));

        fundo = new PanelFundo();
        fundo.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 20));

        JLabel titulo = new JLabel();
        titulo.setLabelFor(fundo);

        try {
            Image tituloImagem = ImageIO.read(getClass().getResource("/imagens/listagem de cadastrados no sistema.png"));
            titulo.setIcon(new ImageIcon(tituloImagem));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        JButton voltar = new JButton();
        voltar.addActionListener(e -> {
            dispose();
        });

        try {
            BufferedImage img = ImageIO.read(getClass().getResource("/imagens/botao-voltar-amarelo.png"));
            voltar.setIcon(new ImageIcon(img));
            voltar.setBorderPainted(false);
            voltar.setFocusPainted(false);
            voltar.setOpaque(false);
            voltar.setContentAreaFilled(false);
            voltar.setBorder(BorderFactory.createEmptyBorder(0,0,0,0));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        fundo.add(voltar);
        voltar.setBounds(new java.awt.Rectangle(20,20,50,50));

        fundo.add(titulo);

        this.add(fundo);

        percorreCadastrados(tracker);

        this.setVisible(true);
    }

    /**
     * Método que, a partir da referencia à Tracker, percorre a lista de cadastrados no sistema e, para cada um deles, cria um painel (JPanel) com informações.
     * @param tracker - referencia à <code>Tracker</code>, gerenciador do mapa.
     */
    private void percorreCadastrados(Tracker tracker){
        for(Marker atual : tracker.getMarkers()){
            Cadastravel objeto = atual.getObjeto();

            JPanel principal = new PanelArredondado(this.getForeground(), objeto, tracker);
            principal.setOpaque(false);
            principal.setLayout(new BorderLayout());
            principal.setPreferredSize(new Dimension(300, 180));

            JPanel infosBasicas = new JPanel();
            infosBasicas.setOpaque(false);
            infosBasicas.setLayout(new BoxLayout(infosBasicas, BoxLayout.Y_AXIS));

            JPanel temDescricao = new JPanel();
            temDescricao.setOpaque(false);

            JLabel nome = new JLabel("Nome: " + objeto.getNomeClasse());

            JLabel imagem = new JLabel();
            try {
                ImageIcon img = new ImageIcon(ImageIO.read(getClass().getResource(objeto.getCaminhoImagem())));
                imagem.setIcon(img);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            JLabel coordenadas = new JLabel("Coordenadas: ( " + objeto.getCoordenadaX() + " , " + objeto.getCoordenadaY() + " )");

            JLabel numero = new JLabel("Número: " + objeto.getNumeros());

            JTextArea descricaoLonga = new JTextArea( "Descrição: " + objeto.getDescricaoLonga(), 5, 25);
            descricaoLonga.setLineWrap(true);
            descricaoLonga.setWrapStyleWord(true);
            descricaoLonga.setBackground(getForeground());
            descricaoLonga.setEditable(false);
            descricaoLonga.setBorder(new EmptyBorder(5, 10, 10, 10));

            infosBasicas.add(Box.createRigidArea(new Dimension(25, 10)));
            infosBasicas.add(nome);
            infosBasicas.add(coordenadas);
            infosBasicas.add(numero);

            temDescricao.add(descricaoLonga);

            principal.add(Box.createRigidArea(new Dimension(30, 30)));
            principal.add(infosBasicas, BorderLayout.WEST);
            principal.add(imagem, BorderLayout.EAST);
            principal.add(temDescricao, BorderLayout.SOUTH);

            fundo.add(principal);
        }

    }

    /**
     * Classe privada que estende JPanel e representa um panel com borda arredondada. Qualquer objeto da classe possui um mouse listener (para hover e frame de informações detalhadas).
     */
    private class PanelArredondado extends JPanel{
        Cadastravel objeto;

        public PanelArredondado(Color corOriginal, Cadastravel objeto, Tracker tracker){
            this.addMouseListener(new PanelMouseListener(corOriginal, tracker));
            this.objeto = objeto;
        }

        /**
         * Método sobrescrito para fazer as bordas arredondadas. Usa um objeto de <code>Graphics2D</code> para preencher o Panel e desenhar a borda com borda radial.
         * @param g the <code>Graphics</code> object to protect
         */
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Dimension arcs = new Dimension(15,15);
            int width = getWidth();
            int height = getHeight();
            Graphics2D graphics = (Graphics2D) g;
            graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            graphics.setColor(getBackground());
            graphics.fillRoundRect(0, 0, width-1, height-1, arcs.width, arcs.height);
            graphics.drawRoundRect(0, 0, width-1, height-1, arcs.width, arcs.height);
        }
    }

    /**
     * Classe privada que estende <code>MouseAdapter</code>. Trata as ações de entrar/sair do panel (adicionando hover) e clicar (abrindo um frame com informações espcíficas do objeto).
     */
    private class PanelMouseListener extends MouseAdapter {
        Color corFundoOriginal;
        Tracker tracker;

        /**
         * Construtor da classe. Recebe a cor do fundo e um objeto de tracker (necessário para a ação de apagar um cadastrado).
         * @param corFundoOriginal
         * @param tracker
         */
        public PanelMouseListener(Color corFundoOriginal, Tracker tracker){
            this.corFundoOriginal = corFundoOriginal;
            this.tracker = tracker;
        }

        /**
         * Tratamento de evento de mouse clicado. Pega o objeto e chama o método que cria o frame de informações específicas dele.
         * @param e <code>MouseEvent</code>
         */
        @Override
        public void mouseClicked(MouseEvent e) {
            PanelArredondado panel = (PanelArredondado) e.getComponent();
            Cadastravel objeto = panel.objeto;
            criaFrame(objeto);
        }

        /**
         * Tratamento de evento de mouse entrando no panel. Altera a cor do panel para cinza claro.
         * @param e <code>MouseEvent</code>
         */
        @Override
        public void mouseEntered(MouseEvent e) {
            PanelArredondado panel = (PanelArredondado) e.getComponent();
            panel.setBackground(Color.GRAY);
            panel.getComponent(3).setBackground(Color.GRAY); //pega JTextArea da descrição e deixa cinza também
        }

        /**
         * Tratamento de evento de mouse saindo do panel. Altera a cor do panel de novo para a cor original.
         * @param e <code>MouseEvent</code>
         */
        @Override
        public void mouseExited(MouseEvent e) {
            PanelArredondado panel = (PanelArredondado) e.getComponent();
            panel.setBackground(corFundoOriginal);
            panel.getComponent(3).setBackground(corFundoOriginal);
        }

        /**
         * Método que, a partir de um objeto <code>Cadastravel</code>, cria um frame listando informações detalhadas e específicas ao objeto.
         * @param objeto
         */
        private void criaFrame(Cadastravel objeto){
            JFrame frame = new JFrame(objeto.getNomeClasse());
            frame.setSize(new Dimension(350, 270));
            frame.getContentPane().setBackground(Color.gray);
            frame.setLayout(new BorderLayout());
            frame.setResizable(false);

            JPanel infosBasicas = new JPanel();
            infosBasicas.setLayout(new BorderLayout());
            infosBasicas.setBackground(Color.gray);

            JLabel titulo = new JLabel("   Informações detalhadas de " + objeto.getNomeClasse());
            titulo.setForeground(Color.black);
            titulo.setFont(new Font("Sans-serif", Font.BOLD, 15));
            titulo.setBorder(new CompoundBorder(titulo.getBorder(), new EmptyBorder(10,0,0,0)));

            JLabel imagem = new JLabel();
            try {
                ImageIcon img = new ImageIcon(ImageIO.read(getClass().getResource(objeto.getCaminhoImagem())));
                img.setImage(img.getImage().getScaledInstance(70, 60, 100)); //redimensionando imagem
                imagem.setIcon(img);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            imagem.setBorder(new EmptyBorder(10,0,0,10));

            JLabel coordenadas = new JLabel("Coordenadas: ( " + objeto.getCoordenadaX() + " , " + objeto.getCoordenadaY() + " )");
            coordenadas.setForeground(Color.black);

            JLabel numero = new JLabel("Número: " + objeto.getNumeros());
            numero.setForeground(Color.black);

            JTextArea descricaoLonga = new JTextArea( "Descrição: " + objeto.getDescricaoLonga(), 4, 25);
            descricaoLonga.setLineWrap(true);
            descricaoLonga.setWrapStyleWord(true);
            descricaoLonga.setBackground(Color.gray);
            descricaoLonga.setEditable(false);
            descricaoLonga.setForeground(Color.black);
            descricaoLonga.setBorder(new EmptyBorder(5, 10, 10, 10));

            JPanel numerocoord = new JPanel();
            numerocoord.setLayout(new BoxLayout(numerocoord, BoxLayout.Y_AXIS));
            numerocoord.setBackground(Color.gray);

            numerocoord.add(Box.createRigidArea(new Dimension(25, 10)));
            numerocoord.add(coordenadas);
            numerocoord.add(numero);

            infosBasicas.add(titulo, BorderLayout.NORTH);
            infosBasicas.add(imagem, BorderLayout.EAST);
            infosBasicas.add(numerocoord, BorderLayout.WEST);
            infosBasicas.add(descricaoLonga, BorderLayout.SOUTH);

            JPanel infosEspecificas = new JPanel();
            infosEspecificas.setBackground(Color.gray);
            infosEspecificas.setLayout(new BoxLayout(infosEspecificas, BoxLayout.Y_AXIS));

            infosEspecificas.add(Box.createRigidArea(new Dimension(10, 0)));

            if(objeto instanceof Ameaca){
                JLabel gravidade = new JLabel("Gravidade da ameaça: " + ((Ameaca) objeto).getGravidade());
                gravidade.setForeground(Color.black);

                infosEspecificas.add(gravidade);

                if(objeto instanceof Blitz){
                    JLabel veiculo = new JLabel("Veículo: " + ((Blitz) objeto).getVeiculo());
                    veiculo.setForeground(Color.black);

                    infosEspecificas.add(veiculo);
                } else if(objeto instanceof Combate){
                    JLabel quantidadeAliados = new JLabel("Quantidade de aliados: " + ((Combate) objeto).getQuantidadeAliados());
                    quantidadeAliados.setForeground(Color.black);

                    JLabel situacaoGeral = new JLabel("Situação geral da batalha: " + ((Combate) objeto).getSituacaoGeral());
                    situacaoGeral.setForeground(Color.black);

                    infosEspecificas.add(quantidadeAliados);
                    infosEspecificas.add(situacaoGeral);
                } else if(objeto instanceof Marcha){
                    JLabel tamanho = new JLabel("Tamanho da marcha: " + ((Marcha) objeto).getTamanhoMarcha() + "km.");
                    tamanho.setForeground(Color.black);

                    infosEspecificas.add(tamanho);
                } else if(objeto instanceof Patrulha){
                    JLabel tipo = new JLabel("Tipo da patrulha: " + ((Patrulha) objeto).getTipo());
                    tipo.setForeground(Color.black);

                    infosEspecificas.add(tipo);
                } else{
                    JLabel carga = new JLabel("Tipo da carga: " + ((Recebimento) objeto).getCarga());
                    carga.setForeground(Color.black);

                    JLabel peso = new JLabel("Peso da carga: " + ((Recebimento) objeto).getPeso());
                    peso.setForeground(Color.black);

                    infosEspecificas.add(carga);
                    infosEspecificas.add(peso);
                }
            }

            JButton botaoExcluir = new JButton();
            botaoExcluir.addActionListener(e -> {
                tracker.excluir(objeto);
                frame.dispose();
            });

            try {
                BufferedImage img = ImageIO.read(getClass().getResource("/imagens/lixo.png"));
                botaoExcluir.setIcon(new ImageIcon(img));
                botaoExcluir.setBorderPainted(false);
                botaoExcluir.setFocusPainted(false);
                botaoExcluir.setOpaque(false);
                botaoExcluir.setContentAreaFilled(false);
                botaoExcluir.setBorder(BorderFactory.createEmptyBorder(0,0,0,0));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            frame.add(infosBasicas, BorderLayout.NORTH);
            frame.add(infosEspecificas, BorderLayout.CENTER);
            frame.add(botaoExcluir, BorderLayout.EAST);
            frame.setVisible(true);
        }
    }
}
