{
    TFile file("B4.root");
    gDirectory->ls();
    Counts->Draw();
    gPad->SetLogx();
}
