const long long __log_table[256]={
	0ULL,
	9205404413830565888ULL,
	9187529797136167936ULL,
	6877310533044398080ULL,
	9152056355200147456ULL,
	5709034963112156160ULL,
	6837709016110757888ULL,
	7962083348011446272ULL,
	9082190594386432000ULL,
	5099031510324217856ULL,
	5654866263813752832ULL,
	6208615328521608192ULL,
	6760294298437286912ULL,
	7309918593314962432ULL,
	7857503461259544576ULL,
	8403063981264951296ULL,
	8946615065705621504ULL,
	4744085731391163392ULL,
	5013873879461628928ULL,
	5282679190570689536ULL,
	5550508799674502144ULL,
	5817369764315253760ULL,
	6083269065737046016ULL,
	6348213609981746176ULL,
	6612210228965227520ULL,
	6875265681534435328ULL,
	7137386654505668608ULL,
	7398579763684491264ULL,
	7658851554867649536ULL,
	7918208504827384832ULL,
	8176657022278507520ULL,
	8434203448828593152ULL,
	8690854059911653376ULL,
	8946615065705621504ULL,
	9201492612034001920ULL,
	4727746390625992704ULL,
	4854310796558692352ULL,
	4980442502823328768ULL,
	5106144457978185728ULL,
	5231419580545185792ULL,
	5356270759416469504ULL,
	5480700854254130176ULL,
	5604712695883226112ULL,
	5728309086678200320ULL,
	5851492800942867456ULL,
	5974266585284059136ULL,
	6096633158979086336ULL,
	6218595214337123328ULL,
	6340155417054632960ULL,
	6461316406564966400ULL,
	6582080796382231552ULL,
	6702451174439559168ULL,
	6822430103421857792ULL,
	6942020121093191680ULL,
	7061223740618854400ULL,
	7180043450882265088ULL,
	7298481716796776448ULL,
	7416540979612490752ULL,
	7534223657218185216ULL,
	7651532144438439936ULL,
	7768468813326047232ULL,
	7885036013449814016ULL,
	8001236072177821696ULL,
	8117071294956244992ULL,
	8232543965583807488ULL,
	8347656346481950720ULL,
	8462410678960804864ULL,
	8576809183481037824ULL,
	8690854059911653376ULL,
	8804547487783817216ULL,
	8917891626540787712ULL,
	9030888615784016896ULL,
	9143540575515491328ULL,
	4627924803188194304ULL,
	4683908894941056000ULL,
	4739723594326883328ULL,
	4795369923323074560ULL,
	4850848894686147584ULL,
	4906161512062344192ULL,
	4961308770096565248ULL,
	5016291654539689984ULL,
	5071111142354307072ULL,
	5125768201818862592ULL,
	5180263792630289408ULL,
	5234598866005106688ULL,
	5288774364779048960ULL,
	5342791223505229824ULL,
	5396650368550870016ULL,
	5450352718192626688ULL,
	5503899182710529024ULL,
	5557290664480562176ULL,
	5610528058065908736ULL,
	5663612250306883584ULL,
	5716544120409573376ULL,
	5769324540033210368ULL,
	5821954373376301056ULL,
	5874434477261526016ULL,
	5926765701219437568ULL,
	5978948887570976768ULL,
	6030984871508815872ULL,
	6082874481177575424ULL,
	6134618537752893440ULL,
	6186217855519407104ULL,
	6237673241947639808ULL,
	6288985497769817088ULL,
	6340155417054632960ULL,
	6391183787280982016ULL,
	6442071389410677760ULL,
	6492818997960165376ULL,
	6543427381071249408ULL,
	6593897300580866048ULL,
	6644229512089887744ULL,
	6694424765031000064ULL,
	6744483802735659008ULL,
	6794407362500139008ULL,
	6844196175650688000ULL,
	6893850967607810048ULL,
	6943372457949684736ULL,
	6992761360474728448ULL,
	7042018383263337472ULL,
	7091144228738791424ULL,
	7140139593727358976ULL,
	7189005169517603840ULL,
	7237741641918907392ULL,
	7286349691319220224ULL,
	7334829992742055936ULL,
	7383183215902734336ULL,
	7431410025263896576ULL,
	7479511080090287104ULL,
	7527487034502833152ULL,
	7575338537532012544ULL,
	7623066233170539520ULL,
	7670670760425370624ULL,
	7718152753369029632ULL,
	7765512841190292480ULL,
	7812751648244202496ULL,
	7859869794101467136ULL,
	7906867893597209600ULL,
	7953746556879109120ULL,
	8000506389454927872ULL,
	8047147992239439872ULL,
	8093671961600763904ULL,
	8140078889406120960ULL,
	8186369363067006976ULL,
	8232543965583807488ULL,
	8278603275589859328ULL,
	8324547867394948096ULL,
	8370378311028285440ULL,
	8416095172280935424ULL,
	8461699012747730944ULL,
	8507190389868660736ULL,
	8552569856969760768ULL,
	8597837963303490560ULL,
	8642995254088623104ULL,
	8688042270549649408ULL,
	8732979549955694592ULL,
	8777807625658970112ULL,
	8822527027132752896ULL,
	8867138280008912896ULL,
	8911641906114977792ULL,
	8956038423510762496ULL,
	9000328346524549120ULL,
	9044512185788841984ULL,
	9088590448275691520ULL,
	9132563637331594240ULL,
	9176432252711983104ULL,
	9220196790615306240ULL,
	4631928871858352128ULL,
	4653707800600642560ULL,
	4675435424398504960ULL,
	4697111984403599360ULL,
	4718737720071321600ULL,
	4740312869176674304ULL,
	4761837667829956608ULL,
	4783312350492265472ULL,
	4804737149990817792ULL,
	4826112297534100480ULL,
	4847438022726838272ULL,
	4868714553584793600ULL,
	4889942116549393408ULL,
	4911120936502191104ULL,
	4932251236779157504ULL,
	4953333239184817152ULL,
	4974367164006210560ULL,
	4995353230026715136ULL,
	5016291654539689984ULL,
	5037182653361982464ULL,
	5058026440847269888ULL,
	5078823229899260928ULL,
	5099573231984739328ULL,
	5120276657146469376ULL,
	5140933714015949824ULL,
	5161544609826032640ULL,
	5182109550423390208ULL,
	5202628740280860672ULL,
	5223102382509635584ULL,
	5243530678871331840ULL,
	5263913829789915136ULL,
	5284252034363504640ULL,
	5304545490376034304ULL,
	5324794394308801536ULL,
	5344998941351875584ULL,
	5365159325415388160ULL,
	5385275739140702208ULL,
	5405348373911451648ULL,
	5425377419864473600ULL,
	5445363065900608512ULL,
	5465305499695391744ULL,
	5485204907709629440ULL,
	5505061475199857664ULL,
	5524875386228690944ULL,
	5544646823675059200ULL,
	5564375969244338176ULL,
	5584063003478362112ULL,
	5603708105765347328ULL,
	5623311454349689856ULL,
	5642873226341675008ULL,
	5662393597727076352ULL,
	5681872743376655360ULL,
	5701310837055561728ULL,
	5720708051432633344ULL,
	5740064558089598976ULL,
	5759380527530185728ULL,
	5778656129189130240ULL,
	5797891531441095680ULL,
	5817086901609498624ULL,
	5836242405975238656ULL,
	5855358209785345024ULL,
	5874434477261526016ULL,
	5893471371608637440ULL,
	5912469055023056896ULL,
	5931427688700979200ULL,
	5950347432846620672ULL,
	5969228446680340480ULL,
	5988070888446685184ULL,
	6006874915422342144ULL,
	6025640683924016128ULL,
	6044368349316230144ULL,
	6063058066019039232ULL,
	6081709987515671552ULL,
	6100324266360092672ULL,
	6118901054184487936ULL,
	6137440501706680320ULL,
	6155942758737461248ULL,
	6174407974187855872ULL,
	6192836296076315648ULL,
	6211227871535837184ULL,
	6229582846821008384ULL,
	6247901367314989056ULL,
	6266183577536419840ULL,
	6284429621146262528ULL,
	6302639640954574848ULL,
	6320813778927214592ULL,
	6338952176192482304ULL,
	6357054973047697408ULL,
	6375122308965704704ULL,
};

const unsigned char __log_exp[256]={
	0,
	8,
	7,
	6,
	6,
	5,
	5,
	5,
	5,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};
