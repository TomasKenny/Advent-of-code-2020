num(1509).
num(1857).
num(1736).
num(1815).
num(1576).
num(1970).
num(1567).
num(1778).
num(1508).
num(1833).
num(1377).
num(1890).
num(1375).
num(1396).
num(1102).
num(1639).
num(1818).
num(1469).
num(1138).
num(1333).
num(1906).
num(1557).
num(1686).
num(1712).
num(1990).
num(1930).
num(1761).
num(1881).
num(1551).
num(1627).
num(1801).
num(1728).
num(1960).
num(1407).
num(1832).
num(1842).
num(1393).
num(1870).
num(1295).
num(1528).
num(251).
num(1945).
num(1589).
num(1850).
num(1650).
num(1793).
num(1997).
num(1758).
num(1477).
num(1697).
num(1081).
num(1825).
num(1899).
num(1171).
num(1104).
num(1839).
num(1974).
num(1630).
num(1831).
num(1671).
num(1723).
num(1811).
num(1489).
num(1647).
num(1486).
num(1107).
num(1786).
num(1680).
num(1942).
num(1640).
num(1112).
num(1703).
num(1315).
num(1769).
num(1966).
num(997).
num(2010).
num(1635).
num(1196).
num(383).
num(1986).
num(1860).
num(1743).
num(1756).
num(1555).
num(1111).
num(1823).
num(48).
num(1953).
num(1083).
num(1804).
num(1933).
num(1626).
num(1895).
num(1807).
num(1669).
num(1783).
num(389).
num(1821).
num(1883).
num(1114).
num(1587).
num(1941).
num(1725).
num(1646).
num(456).
num(1550).
num(1939).
num(1975).
num(1324).
num(1201).
num(1018).
num(1001).
num(1402).
num(1885).
num(1481).
num(1633).
num(1781).
num(1622).
num(1822).
num(1559).
num(1696).
num(1510).
num(1251).
num(1732).
num(1790).
num(1813).
num(1695).
num(1121).
num(704).
num(1964).
num(1984).
num(1763).
num(1656).
num(1183).
num(1771).
num(1276).
num(1764).
num(1810).
num(1992).
num(1213).
num(1840).
num(1318).
num(1965).
num(1943).
num(1549).
num(1768).
num(1506).
num(1949).
num(1739).
num(1852).
num(1787).
num(1570).
num(1988).
num(1357).
num(1909).
num(1837).
num(561).
num(1994).
num(1777).
num(1547).
num(1925).
num(1897).
num(1817).
num(1677).
num(1668).
num(1982).
num(1667).
num(1753).
num(1041).
num(1826).
num(1961).
num(1797).
num(1765).
num(1720).
num(1835).
num(1688).
num(1705).
num(1744).
num(1977).
num(1971).
num(1775).
num(1782).
num(1661).
num(1385).
num(1162).
num(1755).
num(1846).
num(1674).
num(1698).
num(1882).
num(1766).
num(1820).
num(1531).
num(1577).
num(1710).
num(1382).
num(1246).
num(1864).
num(1702).

sum2020(X, Y) :- num(X), num(Y), 2020 is X + Y.
sum2020of3(X, Y, Z) :- num(X), num(Y), num(Z), 2020 is X + Y + Z.
product(P, X, Y) :- P is X * Y.
productof3(P, X, Y, Z) :- P is X * Y * Z.

main :-
        sum2020(X,Y),
        write(X + Y),
        write("\n"),
        product(P, X, Y),
        write("product: "),
        write(P),
        write("\n\n"),
        
        sum2020of3(A, B, C),
        write(A+B+C),
        write("\n"),
        productof3(P2, A, B, C),
        write("product of 3: "),
        write(P2),
        halt.

:- main.
