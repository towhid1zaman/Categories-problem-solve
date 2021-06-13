void task(){
    sp(7);
    double h, m; cin >> h >> m;
    if(m==60)m=0; if(h==12)h=0;
    double h_angle = 0.5*(h*60+m);
    double m_angle = 6*m;
    double angle = abs(h_angle - m_angle);
    cout << min(360 - angle, angle) << endl;
}
