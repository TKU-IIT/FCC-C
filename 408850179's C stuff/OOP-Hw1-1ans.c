char toLetterGrade(unsigned points){
    if(points>100){return 'U';}
    switch(points/10){
        case 10:
        case 9:
        case 8:
            return 'A';
        case 7:
            return 'B';
        case 6:
            return (points>=65)?'C':'D';
        default:
            return 'F';
    }
}