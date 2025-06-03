package main

import "fmt"

func soma(a, b int) int {
	return a + b
}
func divisao(a, b int) int {
	if b == 0 {
		return 0 // Licença poética de exercicio de programação :)
	}
	return a / b
}
func subtracao(a, b int) int {
	return a - b
}
func multiplicacao(a, b int) int {
	return a * b
}

func main() {
	var i, j, opcao, resp int
	runnning := true
	fmt.Println("Digite o primeiro número:")
	fmt.Scan(&i)
	fmt.Println("Digite o segundo número:")
	fmt.Scan(&j)
	for runnning {
		fmt.Printf("1- Soma\n2- Divisão\n3- Subtração\n4- Multiplicação\n5- Sair\n")
		fmt.Println("Selecionne a opção desejada:")
		fmt.Scan(&opcao)
		switch opcao {
		case 1:
			resp = soma(i, j)
			fmt.Printf("Soma: %d\n", resp)
		case 2:
			resp = divisao(i, j)
			fmt.Printf("Divisão: %d\n", resp)
		case 3:
			resp = subtracao(i, j)
			fmt.Printf("Subtração: %d\n", resp)
		case 4:
			resp = multiplicacao(i, j)
			fmt.Printf("Multiplicação: %d\n", resp)
		default:
			fmt.Println("Bye Bye!  :)")
			runnning = false
		}
	}
}
