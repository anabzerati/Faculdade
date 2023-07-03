package ui;

import jdk.nashorn.internal.scripts.JO;
import services.Util;
import ui.TelaInicial;
import ui.mapa.Tracker;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.Encoder;
import java.util.Arrays;
import java.util.Base64;

/**
 * Tela de login. Caso o usuário acerte a senha, os dados são lidos e o usuário entra no sistema. Caso erre, fecha o programa.
 */
public class Login extends JFrame {
    private String passwd;

    /**
     * Construtor da classe. Chama função que lê o arquivo da senha, apresenta a tela de login e valida a senha inserida, direcionando o usuário à tela inicial caso
     * a senha esteja correta ou fechando o programa, caso não esteja.
     */
    public Login() {
        passwd = Util.readPassword();

        setLayout(new FlowLayout());
        setSize(300, 100);

        JLabel senha = new JLabel("Digite a senha: ");
        JPasswordField campoSenha = new JPasswordField(20);
        senha.setLabelFor(campoSenha);

        JButton button = new JButton("OK");
        button.setBackground(Color.darkGray);
        button.setForeground(Color.lightGray);
        button.setFocusPainted(false);
        button.setBorderPainted(false);

        add(senha);
        add(campoSenha);
        add(button);

        setResizable(false);
        setLocationRelativeTo(null);
        setVisible(true);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String senhaDigitada = campoSenha.getText();
                String senhaCriptografada = criptografar(senhaDigitada);

                if (senhaCriptografada.equals(passwd)) {
                    Tracker tracker = new Tracker();
                   tracker = Util.readFile();

                    new TelaInicial(tracker);
                    dispose();
                }
                else
                {
                    JOptionPane.showMessageDialog(new JFrame(), "SENHA INCORRETA", "ERRO", JOptionPane.ERROR_MESSAGE);
                    System.exit(0);
                }
            }
        });
    }

    /**
     * Criptografa a senha e retorna ela encriptografada.
     * @param senha
     * @return
     */
    public static String criptografar(String senha) {
        Base64.Encoder encoder = Base64.getEncoder();
        return encoder.encodeToString(senha.getBytes());
    }

}
