public class Velho extends Imovel {
    @Override
    public double getPreco() {
        double precoBase = super.getPreco();
        return precoBase * 0.90;
    }
}
