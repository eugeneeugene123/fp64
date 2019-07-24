#ifndef FP64_H_INCLUDED
#define FP64_H_INCLUDED


// todo: perl script to generate lookup table directly instead of macros
// done

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


const unsigned long long __reciprocal_div_table[256]={
	18446744073709551615ULL,
	18374966859414961920ULL,
	18303746057634283774ULL,
	18233075223434923605ULL,
	18162948011037096975ULL,
	18093358171914349477ULL,
	18024299552937577151ULL,
	17955766094561388645ULL,
	17887751829051686415ULL,
	17820250878753378164ULL,
	17753257454397162457ULL,
	17686765853444364096ULL,
	17620770458468825424ULL,
	17555265735574889270ULL,
	17490246232850537828ULL,
	17425706578854779386ULL,
	17361641481138401520ULL,
	17298045724797235215ULL,
	17234914171057099320ULL,
	17172241755889618958ULL,
	17110023488658134832ULL,
	17048254450792943009ULL,
	16986929794495126667ULL,
	16926044741468262414ULL,
	16865594581677304334ULL,
	16805574672133968732ULL,
	16745980435707961750ULL,
	16686807359963410649ULL,
	16628050996019877513ULL,
	16569706957437351627ULL,
	16511770919124633614ULL,
	16454238616270540814ULL,
	16397105843297379214ULL,
	16340368452836142607ULL,
	16284022354722914529ULL,
	16228063515015962933ULL,
	16172487955033031553ULL,
	16117291750408345439ULL,
	16062471030168861271ULL,
	16008021975829305809ULL,
	15953940820505558154ULL,
	15900223848045943480ULL,
	15846867392180017495ULL,
	15793867835684432152ULL,
	15741221609565484045ULL,
	15688925192257957520ULL,
	15636975108839884813ULL,
	15585367930262855490ULL,
	15534100272597517150ULL,
	15483168796293918733ULL,
	15432570205456356907ULL,
	15382301247132394832ULL,
	15332358710615731213ULL,
	15282739426762605869ULL,
	15233440267321436173ULL,
	15184458144275386539ULL,
	15135790009197580813ULL,
	15087432852618674804ULL,
	15039383703406513419ULL,
	14991639628157603853ULL,
	14944197730600143081ULL,
	14897055151008344522ULL,
	14850209065627815137ULL,
	14803656686111740481ULL,
	14757395258967641292ULL,
	14711422065014471070ULL,
	14665734418849829856ULL,
	14620329668327074965ULL,
	14575205194042114857ULL,
	14530358408829677580ULL,
	14485786757268850348ULL,
	14441487715197691785ULL,
	14397458789236723212ULL,
	14353697516321110072ULL,
	14310201463241349132ULL,
	14266968226192281612ULL,
	14223995430330256667ULL,
	14181280729338273915ULL,
	14138821804998937765ULL,
	14096616366775060339ULL,
	14054662151397753612ULL,
	14012956922461855233ULL,
	13971498470028536135ULL,
	13930284610234941633ULL,
	13889313184910721216ULL,
	13848582061201305612ULL,
	13808089131197793022ULL,
	13767832311573309660ULL,
	13727809543225712830ULL,
	13688018790926507865ULL,
	13648458042975853218ULL,
	13609125310863530875ULL,
	13570018628935762108ULL,
	13531136054067751328ULL,
	13492475665341843467ULL,
	13454035563731182945ULL,
	13415813871788764811ULL,
	13377808733341771143ULL,
	13340018313191088174ULL,
	13302440796815902010ULL,
	13265074390083273072ULL,
	13227917318962591635ULL,
	13190967829244819032ULL,
	13154224186266421208ULL,
	13117684674637903371ULL,
	13081347597976856547ULL,
	13045211278645428767ULL,
	13009274057492135574ULL,
	12973534293597926411ULL,
	12937990364026425243ULL,
	12902640663578265611ULL,
	12867483604549441999ULL,
	12832517616493601124ULL,
	12797741145988198411ULL,
	12763152656404446523ULL,
	12728750627680984403ULL,
	12694533556101196811ULL,
	12660499954074115854ULL,
	12626648349918837469ULL,
	12592977287652387236ULL,
	12559485326780971313ULL,
	12526171042094549638ULL,
	12493033023464669877ULL,
	12460069875645501883ULL,
	12427280218078013720ULL,
	12394662684697231532ULL,
	12362215923742526737ULL,
	12329938597570875231ULL,
	12297829382473034410ULL,
	12265886968492584970ULL,
	12234110059247785527ULL,
	12202497371756189182ULL,
	12171047636261972200ULL,
	12139759596065925999ULL,
	12108632007358064650ULL,
	12077663639052801058ULL,
	12046853272626645953ULL,
	12016199701958384767ULL,
	11985701733171688359ULL,
	11955358184480114465ULL,
	11925167886034457610ULL,
	11895129679772406079ULL,
	11865242419270465361ULL,
	11835504969598108305ULL,
	11805916207174113034ULL,
	11776475019625050408ULL,
	11747180305645883616ULL,
	11718030974862643210ULL,
	11689025947697141618ULL,
	11660164155233691885ULL,
	11631444539087796092ULL,
	11602866051276769566ULL,
	11574427654092267680ULL,
	11546128319974682674ULL,
	11517967031389378569ULL,
	11489942780704732880ULL,
	11462054570071954402ULL,
	11434301411306647006ULL,
	11406682325772089888ULL,
	11379196344264205334ULL,
	11351842506898185609ULL,
	11324619862996751111ULL,
	11297527470980012472ULL,
	11270564398256909817ULL,
	11243729721118202889ULL,
	11217022524630986255ULL,
	11190441902534704297ULL,
	11163986957138641167ULL,
	11137656799220861353ULL,
	11111450547928576973ULL,
	11085367330679918342ULL,
	11059406283067084809ULL,
	11033566548760853303ULL,
	11007847279416422409ULL,
	10982247634580570264ULL,
	10956766781600104904ULL,
	10931403895531586142ULL,
	10906158159052298415ULL,
	10881028762372454409ULL,
	10856014903148609686ULL,
	10831115786398268838ULL,
	10806330624415664104ULL,
	10781658636688687702ULL,
	10757099049816959484ULL,
	10732651097431011849ULL,
	10708314020112574180ULL,
	10684087065315939397ULL,
	10659969487290395516ULL,
	10635960547003705436ULL,
	10612059512066618457ULL,
	10588265656658397340ULL,
	10564578261453344997ULL,
	10540996613548315209ULL,
	10517520006391192012ULL,
	10494147739710322697ULL,
	10470879119444889609ULL,
	10447713457676206224ULL,
	10424650072559923209ULL,
	10401688288259130426ULL,
	10378827434878341129ULL,
	10356066848398344766ULL,
	10333405870611915128ULL,
	10310843849060360728ULL,
	10288380136970904605ULL,
	10266014093194880899ULL,
	10243745082146735821ULL,
	10221572473743820808ULL,
	10199495643346965904ULL,
	10177513971701821581ULL,
	10155626844880957448ULL,
	10133833654226706467ULL,
	10112133796294743498ULL,
	10090526672798387208ULL,
	10069011690553614528ULL,
	10047588261424777050ULL,
	10026255802271008946ULL,
	10005013734893316130ULL,
	9983861485982336604ULL,
	9962798487066762054ULL,
	9941824174462410976ULL,
	9920937989221943726ULL,
	9900139377085210091ULL,
	9879427788430220112ULL,
	9858802678224729047ULL,
	9838263505978427528ULL,
	9817809735695728095ULL,
	9797440835829139447ULL,
	9777156279233219904ULL,
	9756955543119101681ULL,
	9736838109009577760ULL,
	9716803462694743238ULL,
	9696851094188183190ULL,
	9676980497683699208ULL,
	9657191171512566899ULL,
	9637482618101316762ULL,
	9617854343930030985ULL,
	9598305859491148808ULL,
	9578836679248773252ULL,
	9559446321598472092ULL,
	9540134308827566088ULL,
	9520900167075897608ULL,
	9501743426297072864ULL,
	9482663620220171111ULL,
	9463660286311914255ULL,
	9444732965739290427ULL,
	9425881203332625177ULL,
	9407104547549094051ULL,
	9388402550436670404ULL,
	9369774767598502408ULL,
	9351220758157713294ULL,
	9332740084722618999ULL,
	9314332313352357423ULL,
	9295997013522923649ULL,
	9277733758093605527ULL,
	9259542123273814144ULL,
	9241421688590303745ULL,
};


unsigned cls(unsigned x){
    // count leading sign bits:
    return __builtin_clz(x)|__builtin_clz(-x);
}

long long clsll(long long x){
    // count leading sign bits:
    return __builtin_clzll(x)|__builtin_clzll(-x);
}

long long cloll(long long x){
    // count leading ones:
    return __builtin_clzll(~x);
}

long long mullhi(long long a, long long b){
    // 64bit
#if defined(__x86_64__) || defined(__aarch64__)
    __int128 ab = a;
    __int128 bb = b;
    return (long long) ((ab*bb >> 64)<<1);
#else
    // 32bit
    long long am = (a >> 63);
    long long bm = (b >> 63);
    unsigned long long au = (a^am)-am;
    unsigned long long bu = (b^bm)-bm;
    long long rm = (am^bm);
    au <<= 1;
    bu <<= 1;
    unsigned long long alo = (au&0xffffffff);
    unsigned long long ahi = (au>>32);
    unsigned long long blo = (bu&0xffffffff);
    unsigned long long bhi = (bu>>32);
    unsigned long long ur = ((ahi*bhi>>1) + (alo*bhi>>33)+(blo*ahi>>33));
    unsigned long long r = (ur^rm)-rm;
    long long sr = r;
    return sr;
#endif
}


unsigned long long umullhi(unsigned long long a, unsigned long long b){
#if defined(__x86_64__) || defined(__aarch64__)
    // 64bit
    unsigned __int128 ab = a;
    unsigned __int128 bb = b;
    return (unsigned long long) (ab*bb >> 64);
#else
    // 32bit
    unsigned long long alo = (a&0xffffffff);
    unsigned long long ahi = (a>>32);
    unsigned long long blo = (b&0xffffffff);
    unsigned long long bhi = (b>>32);
    return ahi*bhi + ((alo*bhi>>32)+(blo*ahi>>32));
#endif
}

unsigned long long umullhi2(unsigned long long a, unsigned long long b){
#if defined(__x86_64__) || defined(__aarch64__)
    // 64 bit
    unsigned __int128 ab = a;
    unsigned __int128 bb = b;
    return (unsigned long long) ((ab*bb >> 64) << 1);
#else
    // 32 bit
    unsigned long long alo = (a&0xffffffff);
    unsigned long long ahi = (a>>32);
    unsigned long long blo = (b&0xffffffff);
    unsigned long long bhi = (b>>32);
    return ((ahi*bhi + ((alo*bhi>>32)+(blo*ahi>>32)))<<1);
#endif
}

long mulhi(long a, long b){
    long long all = a;
    long long bll = b;
    return ((all*bll)>>32);
}

long smulhi(unsigned a, long b){
    long long all = a;
    long long bll = b;
    return ((all*bll)>>32);
}

unsigned umulhi2(unsigned a, unsigned b){
    unsigned long long all = a;
    unsigned long long bll = b;
    // faster version of ((all*bll)>>31)
    return (((all*bll)>>32) << 1);
}

unsigned umulhi(unsigned a, unsigned b){
    unsigned long long all = a;
    unsigned long long bll = b;
    return ((all*bll)>>32);
}

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;


typedef union {
  double d;
  struct {
    unsigned long long mantisa : 52;
    unsigned long long exponent : 11;
    unsigned long long sign : 1;
  } parts;
} double_cast;



class fp64{
public:
    fp64(float x);
    fp64(double x);
    fp64(int x);
    fp64(unsigned long x);
    fp64(unsigned x);
    fp64(long x);
    fp64(long long x);
    fp64(unsigned long long x);
    fp64(long long mant, long exp);
    fp64(long long mant, long exp, long isnan);
    fp64();
    operator int();
    operator unsigned();
    operator unsigned long();
    operator unsigned long long();
    operator long();
    operator long long();
    operator float();
    operator double();
    friend fp64 operator - (const fp64 &a);
    friend fp64 operator + (const fp64 &a, const fp64 &b);
    friend fp64 operator - (const fp64 &a, const fp64 &b);
    friend fp64 operator * (const fp64 &a, const fp64 &b);
    friend fp64 operator / (const fp64 &a, const fp64 &b);
    friend fp64 operator + (const double &a, const fp64 &b);
    friend fp64 operator - (const double &a, const fp64 &b);
    friend fp64 operator * (const double &a, const fp64 &b);
    friend fp64 operator / (const double &a, const fp64 &b);
    friend fp64 operator + (const fp64 &a, const double &b);
    friend fp64 operator - (const fp64 &a, const double &b);
    friend fp64 operator * (const fp64 &a, const double &b);
    friend fp64 operator / (const fp64 &a, const double &b);
    fp64& operator += (const fp64 &a);
    fp64& operator -= (const fp64 &a);
    fp64& operator *= (const fp64 &a);
    fp64& operator /= (const fp64 &a);
    fp64& operator += (const double &a);
    fp64& operator -= (const double &a);
    fp64& operator *= (const double &a);
    fp64& operator /= (const double &a);
    fp64 re(void);
    fp64 reT(void);               // tabled (faster) version of "re"
    fp64& operator = (const fp64 &a);
    friend bool operator < (const fp64 &a, const fp64 &b);
    friend bool operator > (const fp64 &a, const fp64 &b);
    friend bool operator == (const fp64 &a, const fp64 &b);
    friend bool operator != (const fp64 &a, const fp64 &b);
    friend bool operator < (const fp64 &a, double &b);
    friend bool operator > (const fp64 &a, double &b);
    friend bool operator == (const fp64 &a, double &b);
    friend bool operator != (const fp64 &a, double &b);
    friend bool operator < (const double &a, const fp64 &b);
    friend bool operator > (const double &a, const fp64 &b);
    friend bool operator == (const double &a, const fp64 &b);
    friend bool operator != (const double &a, const fp64 &b);
    friend std::ostream& operator << (std::ostream &os, const fp64 &a);
    friend std::istream& operator >> (std::istream &is, fp64 &a);
// up to 64 bits precision:
    friend fp64 sin(const fp64 &a);      // sine
    friend fp64 sinr(const fp64 &a);     // the same as sin, but argument must lie in range -PI/2 < x < PI/2
    friend fp64 cos(const fp64 &a);      // cosine
    friend fp64 log(const fp64 &a);      // natural logarithm
    friend fp64 normalize(unsigned long long of, unsigned long long man, unsigned exp, unsigned isnan);
    friend fp64 floor(const fp64 &a);
    friend fp64 ceil(const fp64 &a);
    friend fp64 round(const fp64 &a);
    friend fp64 trunc(const fp64 &a);
    friend fp64 __floor_neg(const fp64 &a);
    friend fp64 __ceil_pos(const fp64 &a);
    friend fp64 __roundpos(const fp64 &a);
    friend fp64 __roundneg(const fp64 &a);
    long long man;
    long exp;
    long isnan; // -1 if is NaN
private:
    static const unsigned sixteen_seventeen = 4042322161U;
    static const unsigned eight_seventeen = (2021161080>>16);
    void init(long long mant, long exp, long isnan);
};

fp64 normalize(unsigned long long of, unsigned long long man, unsigned exp, unsigned isnan){
    fp64 result;
    result.man = man;
    result.exp = exp;
    result.isnan = isnan;
    if (of){
        result.man >>= 1;
        result.man ^= (1ULL<<63);
        result.exp += 1;
        return result;
    } else {
        unsigned shift_amount = clsll(result.man)-1;
        result.man <<= shift_amount;
        result.exp -= shift_amount;
        return result;
    }
}


void fp64::init(long long mman, long eexp, long iisnan){
    unsigned sign_bits = (clsll(mman)&63);
    long long sign = (mman & (1ULL<<63));
    man = (mman << (sign_bits));
    man = (((unsigned long long)man)>>1);
    man |= sign;
    exp = eexp - (sign_bits-1);
    exp = (man == 0) ? -(1<<30):exp;
    isnan = iisnan;
}

fp64::fp64(long long mman, long eexp, long iisnan){
    init(mman, eexp, iisnan);
}

fp64::fp64(long long mman, long eexp){
    init(mman, eexp, 0);
}

fp64::fp64(long long mman){
    init(mman, 0, 0);
}

fp64::fp64(int mman){
    unsigned sign_bits = (cls(mman)&31);
    long long mmanll = (long long) mman;
    mmanll <<= (sign_bits+31);
    man = mmanll;
    exp = -sign_bits-31;
    exp = (man==0) ? (-1<<30):exp;
    isnan = 0;
}

fp64::fp64(unsigned long mman){
    init(mman, 0, 0);
}

fp64::fp64(){
    init(0,0,0);
}

fp64::fp64(unsigned long long x){
    init((x>>1),1,0);
}

fp64::fp64(unsigned mman){
    unsigned sign_bits = (cls(mman)&31);
    long long mmanll = (long long) mman;
    mmanll <<= (sign_bits+31);
    exp = -sign_bits-31;
    man = mmanll;
    exp = (man==0) ? (-1<<30):exp;
    isnan = 0;
}

fp64::fp64(float value){
    float_cast f;
    f.f = value;
    long long nm = f.parts.mantisa + (1ULL << 23);
    nm = f.parts.sign ? -nm:nm;
    if (f.parts.exponent != 255){
        init(nm, ((int)f.parts.exponent-127-23), 0);
    } else {
        init(nm, f.parts.exponent, -1);
    }
}

fp64::fp64(double value){
    double_cast d;
    d.d = value;
    long long nm = d.parts.mantisa + (1ULL<<52);
    nm = d.parts.sign ? -nm:nm;
    if (d.parts.exponent != 2047){
        init(nm, ((int)d.parts.exponent-1023-52), 0);
    } else {
        init(nm, ((int)d.parts.exponent-1023-52), -1);
    }
}

fp64::fp64(long x){
    init(x, 0, 0);
}

fp64::operator unsigned(){
    return (unsigned) operator long long();
}

fp64::operator unsigned long(){
    return (unsigned long) operator long long();
}

fp64::operator unsigned long long(){
    return (unsigned long long) operator long long();
}


fp64::operator long long(){
    unsigned long long iszero = ((63LL-(long long)exp)>>63)|(((long long)exp+63LL)>>63)|isnan|(((long long)isnan)<<32);
    long long mask = (long long) (exp >> 31);
    long long to_return = ((~iszero) & (((man << exp)& (~mask)) | ((man >> -exp) & (mask))));
    return to_return - (to_return >> 63);                                                          // negative values handling
}

fp64::operator long(){
    return (long) operator long long();
}

fp64::operator int(){
    return (int) operator long long();
}

fp64::operator float(){
    float_cast f;
    if (isnan) {
        f.parts.exponent = 255;
        f.parts.mantisa = 1;
        return f.f;
    }
    if (man == 0){
        return 0.0f;
    }
    // calculate absolute value:
    long long mask = (man >> 63);
    unsigned long long absval = (man ^ mask) - mask;
    f.parts.sign = (mask&1);
    f.parts.mantisa = ((absval >> 39) & ((1<<23)-1));
    long nexp = (exp+62+127);
    if (nexp > 255){
        // positive and negative infinity (sign is already set)
        f.parts.mantisa = 0;
        f.parts.exponent = 255;
        return f.f;
    }
    if (nexp < 0){
        f.parts.mantisa = 0;
        f.parts.exponent = 0;
        // denormals are flushed to zero
        // todo: normal denormal handling
    }
    f.parts.exponent = nexp;
    return f.f;
}

fp64::operator double(){
    double_cast d;
    if (isnan) {
        d.parts.exponent = 2047;
        d.parts.mantisa = 1;
        return d.d;
    }
    if (man == 0){
        return 0.0;
    }
    // calculate absolute value:
    long long mask = (man >> 63);
    unsigned long long absval = (man ^ mask) - mask;
    d.parts.sign = (mask&1);
    d.parts.mantisa = ((absval >> 10) & ((1ULL<<52)-1));
    long nexp = (exp+62+1023);
    if (nexp > 2047){
        // positive and negative infinity (sign is already set)
        d.parts.mantisa = 0;
        d.parts.exponent = 1023;
        return d.d;
    }
    if (nexp < 0){
        d.parts.mantisa = 0;
        d.parts.exponent = 0;
        // denormals are flushed to zero
        // todo: normal denormal handling
    }
    d.parts.exponent = nexp;
    return d.d;
}

fp64 operator -(const fp64 &a){
    fp64 result;
    result.man = -a.man;
    result.exp = a.exp;
    result.isnan = a.isnan;
    return result;
}

fp64 operator + (const fp64 &a, const fp64 &b){
    //long long maxa = (long long)(b.exp - a.exp);
    //maxa >>= 63;
    //long imaxa = (long) maxa;
    long long bm,lm;
    long long be,le;
    fp64 result;
    // todo: sometimes it is better to use commented variant. when?
    //bm = (a.man&maxa) | (b.man&(~maxa));
    //lm = (b.man&maxa) | (a.man&(~maxa));
    //be = (a.exp&imaxa) | (b.exp&(~imaxa));
    //le = (b.exp&imaxa) | (a.exp&(~imaxa));
    bm = (a.exp > b.exp) ? a.man:b.man;
    lm = (a.exp > b.exp) ? b.man:a.man;
    be = (a.exp > b.exp) ? a.exp:b.exp;
    le = (a.exp > b.exp) ? b.exp:a.exp;

    int diffexp = be-le;
    long long ignoremin = (long long) ((diffexp-63) >> 31);
    long long of = __builtin_saddll_overflow(bm, (ignoremin & (lm >> diffexp)), &(result.man));
    return normalize(of, result.man, be, (a.isnan|b.isnan));
    // todo: check >>1 | 1 when overflow happens (optimization)
    //long long overman = (bm >> 1) + ((ignoremin & (lm >> diffexp))>>1);
    // todo: optimize this!!!
    //return fp64( ((result.man&(of-1))|(overman&(-of))), be+of, (a.isnan|b.isnan) );
}

fp64 operator - (const fp64 &b, const fp64 &a){
    fp64 c(-a.man, a.exp, a.isnan);
    return c+b;
}

fp64 operator * (const fp64 &a, const fp64 &b){
    fp64 result;
    result.man = mullhi(b.man, a.man);
    unsigned of = (cls(result.man >> 32)&2);
    result.man = of ? (result.man << 1):result.man;
    result.exp = of ? (b.exp - 1):b.exp;
    result.exp += a.exp+63;
    result.isnan = a.isnan | b.isnan;
    return result;
}

fp64& fp64::operator = (const fp64 &a){
    man = a.man;
    exp = a.exp;
    isnan = a.isnan;
    return *this;
}

fp64& fp64::operator += (const fp64 &a){
    *this = *this+a;
    return *this;
}

fp64& fp64::operator -= (const fp64 &a){
    *this = *this-a;
    return *this;
}

fp64& fp64::operator *= (const fp64 &a){
    *this = *this*a;
    return *this;
}


fp64 fp64::re(){
    // returns reciprocal:
    // Newton-Raphson
    // todo: other method (deriv) is faster
    if (man == 0) return fp64(0, 0, -1);
    unsigned long long D = ((man>>63)^man) - (man>>63);
    unsigned Du = (D >> 31);
    unsigned long long sign = (man >> 63);
    unsigned mult = (((D & (~(1ULL << 62)))>>46)*eight_seventeen);
    unsigned x0 = (sixteen_seventeen - mult);

    x0 += smulhi(x0, -umulhi2(Du, x0));
    x0 += smulhi(x0, -umulhi2(Du, x0));
    x0 += smulhi(x0, -umulhi2(Du, x0));

    unsigned long long x0ll = (((unsigned long long)x0)<<31) + (mullhi((((unsigned long long)x0)<<31), -umullhi2((D<<1), (((unsigned long long)x0)<<32)))>>1);
    // todo: optimize this!!!
    //return fp64(((x0ll ^ sign) - sign), -exp-125, 0);
    // done:
    fp64 result;
    result.man = (x0ll^sign)-sign;
    result.exp = -exp-125;
    result.isnan = isnan;
    return result;
}

fp64 fp64::reT(){
    // returns reciprocal:
    // 1/x = (1/x0)*(1-y+y^2-y^3+y^4-y^5+y^6-y^7)
    // y = deltax/x0
    // debug: 1.22801 and 1.22802. what is the difference?
    if (man == 0) return fp64(0,0,-1);
    unsigned long long sign = (man>>63);
    unsigned long long D = ((man>>63)^man) - (man>>63);
    unsigned Du = (D>>54);          // 31+24
    unsigned long long x0 = (((unsigned long long)Du) << 55);
    unsigned long long re0 = __reciprocal_div_table[(Du&255)];
    unsigned long long deltax = (D<<1)-x0;
    unsigned long long y = ((umullhi(deltax, re0))<<1);
    unsigned long long omy = -y;
    unsigned long long yy = (umullhi(y,y));
    unsigned long long yyyy = umullhi(yy,yy);
    unsigned long long quatro = omy+(umullhi(yy,omy)<<0);
    unsigned long long dentro = quatro+((umullhi(yyyy,quatro)));
    unsigned long long rex = (y==0) ? (re0>>1) : (umullhi(re0,dentro)>>1)+1;
    fp64 result;
    result.man = (rex^sign)-sign;
    result.exp = -exp-125;
    result.isnan = isnan;
    return result;
}



fp64 operator / (const fp64 &a, const fp64 &b){
    fp64 c = b;
    return a*(c.reT());
}

fp64& fp64::operator /= (const fp64 &a){
    fp64 c = a;
    *this = *this*c.re();
    return *this;
}

bool operator < (const fp64 &a, const fp64 &b){
    // todo: optimize this!!!
    //fp64 c = a-b;
    //return (c.man < 0)&&(!c.isnan);
    // done: (optimize better!)
    if ((a.man ^ b.man) < 0) return (a.man < b.man)&&(!a.isnan)&&(!b.isnan);
    if (a.exp != b.exp) return (((a.man>0)&&(a.exp<b.exp))||((a.man<=0)&&(a.exp>b.exp)))&&(!a.isnan)&&(!b.isnan);
    // same signs, same exponents:
    return (a.man < b.man)&&(!a.isnan)&&(!b.isnan);

}

bool operator > (const fp64 &a, const fp64 &b){
    return (b < a);
}

bool operator == (const fp64 &a, const fp64 &b){
    return ((a.man==b.man)&&((a.exp==b.exp)||(a.man==0)))&&(!a.isnan)&&(!b.isnan);
}

bool operator != (const fp64 &a, const fp64 &b){
    return !(a==b);
}

bool operator < (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a<(fp64)b);
}

bool operator > (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a>(fp64)b);
}

bool operator == (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a == (fp64)b);
}

bool operator != (const fp64 &a, const double &b){
    // todo: optimize this!
    return (a != (fp64)b);
}

bool operator < (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a<b);
}

bool operator > (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a>b);
}

bool operator == (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a == b);
}

bool operator != (const double &a, const fp64 &b){
    // todo: optimize this!
    return ((fp64)a != b);
}

fp64 operator + (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a+b;
}

fp64 operator - (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a-b;
}

fp64 operator * (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a*b;
}

fp64 operator / (const double &a, const fp64 &b){
    // todo: optimize this!
    return (fp64)a/b;
}

fp64 operator + (const fp64 &a, const double &b){
    // todo: optimize this!
    return a+(fp64)b;
}

fp64 operator - (const fp64 &a, const double &b){
    // todo: optimize this!
    return a-(fp64)b;
}

fp64 operator * (const fp64 &a, const double &b){
    // todo: optimize this!
    return a*(fp64)b;
}

fp64 operator / (const fp64 &a, const double &b){
    // todo: optimize this!
    return a/(fp64)b;
}

fp64& fp64::operator += (const double &a){
    // todo: optimize this!
    *this += (fp64)a;
    return *this;
}

fp64& fp64::operator -= (const double &a){
    // todo: optimize this!
    *this -= (fp64)a;
    return *this;
}

fp64& fp64::operator *= (const double &a){
    // todo: optimize this!
    *this *= (fp64)a;
    return *this;
}

fp64& fp64::operator /= (const double &a){
    // todo: optimize this!
    *this /= (fp64)a;
    return *this;
}

fp64 trunc(const fp64 &a){
    // chop fractional part:
    fp64 result;
    result.isnan = a.isnan;
    if (a.exp > 0){
        // infinity?
        return a;
    } else {
        // todo: optimize it!!!
        long long sign = (a.man >> 63);
        result.man = (a.man^sign)-sign;
        unsigned long long resultman = result.man;
        resultman >>= (-a.exp);
        resultman <<= (-a.exp);
        result.man = resultman;
        result.exp = a.exp;
        result.man = (result.man^sign)-sign;
    }
    return result;
}

fp64 round(const fp64 &a){
    // round to the nearest value:
   if (a.exp >= 0){
        fp64 b;
        b = a;
        b.isnan = -1;
        return b;
   } else {
        if (a.man > 0) return __roundpos(a);
        else return __roundneg(a);
   }
}

fp64 __roundpos(const fp64 &a){
    fp64 result;
    result.isnan = a.isnan;
    result.man = a.man;
    result.exp = a.exp;
    result.man >>= (-result.exp + 1);
    result.man += 1;
    result.man >>= 1;
    result.man <<= (-result.exp);
    if (result.man & (1ULL << 63)){
        // overflow
        result.man >>= 1;
        result.exp += 1;
    }
    return result;
}

fp64 __roundneg(const fp64 &a){
    fp64 result;
    result.isnan = a.isnan;
    result.man = a.man;
    result.exp = a.exp;
    result.man >>= (-result.exp + 1);
    result.man -= 1;
    result.man >>= 1;
    result.man <<= (-result.exp);
    if (result.man & (1ULL << 63)){
        // overflow
        result.man >>= 1;
        result.exp += 1;
    }
    return result;
}


fp64 floor(const fp64 &a){
    // calculate floor of the value (round down to the nearest integer)
    if (a.man >= 0) return trunc(a);
    else return __floor_neg(a);
}

fp64 ceil(const fp64 &a){
    // calculate ceil of the value (round up to the nearest integer)
    if (a.man < 0) return trunc(a);
    else return __ceil_pos(a);
}

fp64 __floor_neg(const fp64 &a){
    if (a.exp > 0){
        // infinity?
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = -1;
    } else if (a.exp == 0){
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = a.isnan;
    } else {
        fp64 result;
        result.isnan = a.isnan;
        result.man = a.man;
        result.man >>= (-a.exp);
        result.man -= 1;
        unsigned signs = cloll(result.man);
        result.man <<= (signs-1);
        result.exp = -(signs-1);
        return result;
    }
}

fp64 __ceil_pos(const fp64 &a){
    if (a.exp > 0){
        // infinity?
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = -1;
    } else if (a.exp == 0){
        fp64 result;
        result.man = a.man;
        result.exp = a.exp;
        result.isnan = a.isnan;
    } else {
        fp64 result;
        result.isnan = a.isnan;
        result.man = a.man;
        result.man >>= (-a.exp);
        result.man += 1;
        unsigned signs = __builtin_clzll(result.man);
        result.man <<= (signs-1);
        result.exp = -(signs-1);
        return result;
    }
}



// math functions:
fp64 sinr(const fp64 &a){
// algorithm for calculating sine function (60-61 bits of precision are guaranteed)
// sin(x) = x+
// -1.666666666666666455027514024765045391390e-1* x^3 +
// 8.333333333333114005518116351849428382702e-3* x^5 +
// -1.984126984118596130918508421649618709748e-4* x^7 +
// 2.755731920778698167648701758421693093376e-6* x^9 +
// -2.505210660664064422936006224669604274226e-8* x^11 +
// 1.605892783658265569622248292940125516955e-10* x^13 +
// -7.642712930271124715062339043717404392317e-13* x^15 +
// 2.718496391757936169840814495224274873348e-15* x^17

// = x(1-x^2(...-...x^2-...x^4+...x^6-...+...-...+...x^14))
// = ..

// xx represents part of 4 (max val of x = pi/2 < 2)
// so a0 = ..*2^66 (unsigned part of 0.25)
// a1 = ..*2^68
// a2 = ..*2^70
// ..
    const unsigned long long a0 = 12297829382473032849ULL;
    const unsigned long long a1 = 2459565876494542147ULL;
    const unsigned long long a2 = 234244369188972280ULL;
    const unsigned long long a3 = 13013576058459312ULL;
    const unsigned long long a4 = 473220914257907ULL;
    const unsigned long long a5 = 12133782810608ULL;
    const unsigned long long a6 = 230986824832ULL;
    const unsigned long long a7 = 3286460478ULL;

    // step 0: get sign of x
    unsigned long long sign = (a.man >> 63);
    unsigned long long absman = (a.man^sign)-sign;

    // step 1: calculate x^2
    // mullhi gives x*x*2
    const long exp_PI_2 = -62;
    // 2^64 = 4;
    unsigned long long xx = umullhi((absman<<1),(absman<<1))>>((exp_PI_2-a.exp)*2);    // 1.2 (+)
    // step 2: calculate everything
    unsigned long long p1 = a0-umullhi(a1,xx);
    unsigned long long p2 = a2-umullhi(a3,xx);
    unsigned long long p3 = a4-umullhi(a5,xx);
    unsigned long long p4 = a6-umullhi(a7,xx);
    unsigned long long xxxx = umullhi(xx,xx);
    unsigned long long q1 = umullhi(p2,xxxx)+p1;
    unsigned long long q2 = umullhi(p4,xxxx)+p3;
    unsigned long long xxxxxxxx = umullhi(xxxx,xxxx);
    unsigned long long r = umullhi(q2,xxxxxxxx)+q1;
    unsigned long long xxr = umullhi(xx,r);
    unsigned long long omxxr = -xxr;
    long long newman = mullhi(absman,(omxxr>>1));
    long newexp = a.exp;
    //if (!(newman&(1ULL<<62))) {
    //    newman <<= 1;
    //    newexp -= 1;
    //}
    unsigned shift_amount = ((newman>>62)&1)^1;
    newman <<= shift_amount;
    newexp -= shift_amount;
    fp64 result;
    result.man = newman;
    result.exp = newexp;
    result.isnan = a.isnan;
    // apply sign:
    result.man = (result.man^sign)-sign;
    // TODO: optimize sign handling!!! maybe change a little shift_amount function?
    return result;
}

fp64 sin(const fp64 &a){
    // example which explains normal range reduction algorithm:
    // 175 % 17 = ceil(((175*(32/17))&31)*(17/32))
    // so
    // (1.23 * 2^32) fmod PI = ceil (((1.23*2^32*(2^32/pi))&(2^32-1))*(pi/2^32))

    // simple range reduction algorithm:
    // x-> int128
    // (1/pi) -> int128
    // pi -> int128
    // x-(1/pi)*x*pi -> int128
    // uses 2 int128 multiplications

    // TODO: implement first algorithm
    // right now simply calculate x - long long(x*(1/(2*Pi)))*2*Pi
    // todo: optimize this algorithm (use integer arithmetic, not fp64) and put it into sini function (imprecise range reduction)

    fp64 dpi;  // pi*2
    dpi.man = 7244019458077122842ULL;
    dpi.exp = -60;
    dpi.isnan = 0;

    fp64 rdpi;   // (1/pi*2)
    rdpi.man = 5871781006564002452;
    rdpi.exp = -65;
    rdpi.isnan = 0;

    fp64 pi;   // 3.1415 ..
    pi.man = 7244019458077122842ULL;
    pi.exp = -61;
    pi.isnan = 0;

    fp64 hpi;  // pi/2
    hpi.man = 7244019458077122842ULL;
    hpi.exp = -62;
    hpi.isnan = 0;

    fp64 x = a;
    fp64 z = (long long)(x*rdpi);
    x = x - z*dpi; // now x lies in range [0;2*pi]:
    x = (x.man > 0) ? x:x+dpi;

    // now reduce x to range [0;pi]
    fp64 x1 = x-pi;
    fp64 y = x;
    y = (x1.man > 0) ? x1 : x;

    unsigned long long sign = ~(x1.man>>63);
    // now reduce y to range [0;pi/2]
    fp64 y1 = y-hpi;
    fp64 t = y;
    t = (y1.man < 0) ? y:pi-y;
    t.man = (t.man^sign)-sign;

    return sinr(t);

}

fp64 cos(const fp64 &a){
    fp64 hpi;  // pi/2
    hpi.man = 7244019458077122842ULL;
    hpi.exp = -62;
    hpi.isnan = 0;
    return sin(hpi-a);
}

fp64 log(const fp64 &a){
    // 62 bits and better precision:
    // log (1.7*2^23) = logt(179)+logp(1.000459770114942528735632183908)+23*log2
    // requires reciprocal table (reciprocal_table.h)
    const unsigned long long one_third = 3074457345618258602ULL;
    const unsigned long long one_fifth = 1844674407370955161ULL;
    const unsigned long long one_sixth = 1537228672809129301ULL;
    const unsigned long long one_seventh = 1317624576693539401ULL;

    fp64 result;
    unsigned long long man = a.man;
    // step 0 : nan for negative values
    result.isnan = (a.man >> 63);
    // step 1 : get i
    unsigned i = ((a.man >> 54)&255);
    // step 2: logt
    man = mullhi(man, (__reciprocal_div_table[i]>>1))+1;
    unsigned long long logt = __log_table[i];
    // step 3: logp (7th degree polynomial)
    unsigned long long x = ((man&(~(1ULL<<62)))<<1);
    // ln(1+x) = x - x^2/2 + x^3/3 - x^4/4 + x^5/5 - x^6/6 + x^7/7
    unsigned long long xx = mullhi(x,x);
    unsigned long long p1 = x-(xx>>1);
    unsigned long long p2 = mullhi(x, one_third)-(xx>>2);
    unsigned long long p3 = mullhi(x, one_fifth)-mullhi(xx,one_sixth);
    unsigned long long p4 = mullhi(x, one_seventh);
    unsigned long long xxxx = mullhi(xx,xx);
    unsigned long long q1 = p1+mullhi(p2,xx);
    unsigned long long q2 = p3+mullhi(p4,xx);
    unsigned long long logp = q1+mullhi(q2,xxxx);

    //result.man = logt + (logp<<(__log_exp[i]));
    long long of = __builtin_saddll_overflow(logt, (logp<<(__log_exp[i])), &(result.man));
    if (of) {
        result.man >>= 1;
        unsigned long long sign = (result.man & (1ULL << 62));
        result.man ^= (sign<<1);
    }
    result.exp = -63-__log_exp[i]+of;
    result.isnan |= a.isnan;

    // todo: optimize it
    // add a.exp * ln(2)
    // fp64 aexp = (int)a.exp+62;
    fp64 aexp;
    unsigned shift_amount = cls(a.exp+62);
    aexp.man = (((long long)a.exp+62)<<(31+shift_amount));
    aexp.exp = -31-shift_amount;
    aexp.isnan = 0;
    fp64 ln2;
    ln2.man = 6393154322601327830;
    ln2.exp = -63;
    ln2.isnan = 0;

    return result + aexp*ln2;

}


std::ostream& operator << (std::ostream &os, const fp64 &a){
    // todo: full 64 bit precision
    fp64 b = a;
    os << (double)b;
    return os;
}

std::istream& operator >> (std::istream &is, fp64 &a){
    // todo: full 64 bit precision
    double x;
    is >> x;
    a = (fp64)x;
    return is;
}




#endif // FP64_H_INCLUDED
