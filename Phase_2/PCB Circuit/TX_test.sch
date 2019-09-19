<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Phase_2">
<description>All the components needed for Phase 2</description>
<packages>
<package name="DIP762W53P254L2215H508Q20B" urn="urn:adsk.eagle:footprint:13336085/1">
<description>20-DIP, 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span, 22.16 X 6.60 X 5.08 mm body
&lt;p&gt;20-pin DIP package with 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span with body size 22.16 X 6.60 X 5.08 mm&lt;/p&gt;</description>
<circle x="-5.0574" y="11.43" radius="0.25" width="0" layer="21"/>
<wire x1="-3.3" y1="12.4874" x2="3.3" y2="12.4874" width="0.12" layer="21"/>
<wire x1="-3.3" y1="-12.4874" x2="3.3" y2="-12.4874" width="0.12" layer="21"/>
<wire x1="3.3" y1="-12.31" x2="-3.3" y2="-12.31" width="0.12" layer="51"/>
<wire x1="-3.3" y1="-12.31" x2="-3.3" y2="12.31" width="0.12" layer="51"/>
<wire x1="-3.3" y1="12.31" x2="3.3" y2="12.31" width="0.12" layer="51"/>
<wire x1="3.3" y1="12.31" x2="3.3" y2="-12.31" width="0.12" layer="51"/>
<pad name="1" x="-3.81" y="11.43" drill="0.7434" diameter="1.4868"/>
<pad name="2" x="-3.81" y="8.89" drill="0.7434" diameter="1.4868"/>
<pad name="3" x="-3.81" y="6.35" drill="0.7434" diameter="1.4868"/>
<pad name="4" x="-3.81" y="3.81" drill="0.7434" diameter="1.4868"/>
<pad name="5" x="-3.81" y="1.27" drill="0.7434" diameter="1.4868"/>
<pad name="6" x="-3.81" y="-1.27" drill="0.7434" diameter="1.4868"/>
<pad name="7" x="-3.81" y="-3.81" drill="0.7434" diameter="1.4868"/>
<pad name="8" x="-3.81" y="-6.35" drill="0.7434" diameter="1.4868"/>
<pad name="9" x="-3.81" y="-8.89" drill="0.7434" diameter="1.4868"/>
<pad name="10" x="-3.81" y="-11.43" drill="0.7434" diameter="1.4868"/>
<pad name="11" x="3.81" y="-11.43" drill="0.7434" diameter="1.4868"/>
<pad name="12" x="3.81" y="-8.89" drill="0.7434" diameter="1.4868"/>
<pad name="13" x="3.81" y="-6.35" drill="0.7434" diameter="1.4868"/>
<pad name="14" x="3.81" y="-3.81" drill="0.7434" diameter="1.4868"/>
<pad name="15" x="3.81" y="-1.27" drill="0.7434" diameter="1.4868"/>
<pad name="16" x="3.81" y="1.27" drill="0.7434" diameter="1.4868"/>
<pad name="17" x="3.81" y="3.81" drill="0.7434" diameter="1.4868"/>
<pad name="18" x="3.81" y="6.35" drill="0.7434" diameter="1.4868"/>
<pad name="19" x="3.81" y="8.89" drill="0.7434" diameter="1.4868"/>
<pad name="20" x="3.81" y="11.43" drill="0.7434" diameter="1.4868"/>
<text x="0" y="13.1224" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-13.1224" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
<package name="SI4663F30">
<description>The package of &lt;B&gt;Si4663F30&lt;/B&gt; shown on the diven datasheet from NiceRF</description>
<wire x1="-19" y1="10" x2="-19" y2="-10" width="0.127" layer="21"/>
<wire x1="-19" y1="-10" x2="-14" y2="-10" width="0.127" layer="21"/>
<wire x1="-14" y1="-10" x2="-10" y2="-10" width="0.127" layer="21"/>
<wire x1="-10" y1="-10" x2="-6" y2="-10" width="0.127" layer="21"/>
<wire x1="-6" y1="-10" x2="-2" y2="-10" width="0.127" layer="21"/>
<wire x1="-2" y1="-10" x2="2" y2="-10" width="0.127" layer="21"/>
<wire x1="2" y1="-10" x2="6" y2="-10" width="0.127" layer="21"/>
<wire x1="6" y1="-10" x2="10" y2="-10" width="0.127" layer="21"/>
<wire x1="10" y1="-10" x2="14" y2="-10" width="0.127" layer="21"/>
<wire x1="14" y1="-10" x2="19" y2="-10" width="0.127" layer="21"/>
<wire x1="19" y1="-10" x2="19" y2="-4" width="0.127" layer="21"/>
<wire x1="19" y1="-4" x2="19" y2="-2" width="0.127" layer="21"/>
<wire x1="19" y1="-2" x2="19" y2="10" width="0.127" layer="21"/>
<wire x1="19" y1="10" x2="14" y2="10" width="0.127" layer="21"/>
<wire x1="14" y1="10" x2="10" y2="10" width="0.127" layer="21"/>
<wire x1="10" y1="10" x2="6" y2="10" width="0.127" layer="21"/>
<wire x1="6" y1="10" x2="-19" y2="10" width="0.127" layer="21"/>
<smd name="P$1" x="-14" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$2" x="-10" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$3" x="-6" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$4" x="-2" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$5" x="2" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$6" x="6" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$7" x="10" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$8" x="14" y="-10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$9" x="14" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$10" x="10" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$11" x="6" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$12" x="2" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$13" x="-2" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$14" x="-6" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$15" x="-10" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<smd name="P$16" x="-14" y="10" dx="3" dy="2" layer="1" rot="R90"/>
<circle x="-17.5" y="-8.5" radius="0.5" width="1" layer="21"/>
<text x="-1" y="-3.5" size="1.27" layer="21" rot="R90">Si4663F30</text>
<text x="-19.05" y="-2.54" size="1.27" layer="21" rot="R90">&gt;NAME</text>
<wire x1="19" y1="-2" x2="18" y2="-2" width="0.127" layer="21"/>
<wire x1="19" y1="-4" x2="18" y2="-4" width="0.127" layer="21"/>
</package>
<package name="INDCAV400P3800X2000X400-16N" urn="urn:adsk.eagle:footprint:13335260/1" locally_modified="yes">
<description>16-Chiparray 2-Side Flat, 4.00 mm pitch, 38.00 X 20.00 X 4.00 mm body
&lt;p&gt;16-pin Chiparray 2-Side Flat package with 4.00 mm pitch with body size 38.00 X 20.00 X 4.00 mm&lt;/p&gt;</description>
<circle x="-10.504" y="15.3899" radius="0.25" width="0" layer="21"/>
<wire x1="-10" y1="15.1399" x2="-10" y2="19" width="0.12" layer="21"/>
<wire x1="-10" y1="19" x2="10" y2="19" width="0.12" layer="21"/>
<wire x1="10" y1="19" x2="10" y2="15.1399" width="0.12" layer="21"/>
<wire x1="-10" y1="-15.1399" x2="-10" y2="-19" width="0.12" layer="21"/>
<wire x1="-10" y1="-19" x2="10" y2="-19" width="0.12" layer="21"/>
<wire x1="10" y1="-19" x2="10" y2="-15.1399" width="0.12" layer="21"/>
<wire x1="10" y1="-19" x2="-10" y2="-19" width="0.12" layer="51"/>
<wire x1="-10" y1="-19" x2="-10" y2="19" width="0.12" layer="51"/>
<wire x1="-10" y1="19" x2="10" y2="19" width="0.12" layer="51"/>
<wire x1="10" y1="19" x2="10" y2="-19" width="0.12" layer="51"/>
<smd name="1" x="-10.06" y="14" dx="3" dy="2" layer="1"/>
<smd name="2" x="-10.06" y="10" dx="3" dy="2" layer="1"/>
<smd name="3" x="-10.06" y="6" dx="3" dy="2" layer="1"/>
<smd name="4" x="-10.06" y="2" dx="3" dy="2" layer="1"/>
<smd name="5" x="-10.06" y="-2" dx="3" dy="2" layer="1"/>
<smd name="6" x="-10.06" y="-6" dx="3" dy="2" layer="1"/>
<smd name="7" x="-10.06" y="-10" dx="3" dy="2" layer="1"/>
<smd name="8" x="-10.06" y="-14" dx="3" dy="2" layer="1"/>
<smd name="9" x="10.06" y="-14" dx="3" dy="2" layer="1"/>
<smd name="10" x="10.06" y="-10" dx="3" dy="2" layer="1"/>
<smd name="11" x="10.06" y="-6" dx="3" dy="2" layer="1"/>
<smd name="12" x="10.06" y="-2" dx="3" dy="2" layer="1"/>
<smd name="13" x="10.06" y="2" dx="3" dy="2" layer="1"/>
<smd name="14" x="10.06" y="6" dx="3" dy="2" layer="1"/>
<smd name="15" x="10.06" y="10" dx="3" dy="2" layer="1"/>
<smd name="16" x="10.06" y="14" dx="3" dy="2" layer="1"/>
<text x="0" y="19.635" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-19.635" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
<package name="ANTENNA">
<pad name="P$1" x="0" y="0" drill="1" shape="square"/>
<text x="-1.27" y="1.27" size="0.6096" layer="21">Antenna</text>
</package>
</packages>
<packages3d>
<package3d name="DIP762W53P254L2215H508Q20B" urn="urn:adsk.eagle:package:13336042/1" type="model">
<description>20-DIP, 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span, 22.16 X 6.60 X 5.08 mm body
&lt;p&gt;20-pin DIP package with 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span with body size 22.16 X 6.60 X 5.08 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="DIP762W53P254L2215H508Q20B"/>
</packageinstances>
</package3d>
<package3d name="INDCAV400P3800X2000X400-16N" urn="urn:adsk.eagle:package:13333453/1" type="model">
<description>16-Chiparray 2-Side Flat, 4.00 mm pitch, 38.00 X 20.00 X 4.00 mm body
&lt;p&gt;16-pin Chiparray 2-Side Flat package with 4.00 mm pitch with body size 38.00 X 20.00 X 4.00 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="INDCAV400P3800X2000X400-16N"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MSP430G2553IN20">
<wire x1="-15.24" y1="30.48" x2="-15.24" y2="-25.4" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-25.4" x2="15.24" y2="-25.4" width="0.254" layer="94"/>
<wire x1="15.24" y1="-25.4" x2="15.24" y2="30.48" width="0.254" layer="94"/>
<wire x1="15.24" y1="30.48" x2="-15.24" y2="30.48" width="0.254" layer="94"/>
<circle x="-12.7" y="27.94" radius="1.27" width="0.254" layer="94"/>
<pin name="P$1" x="-20.32" y="22.86" visible="pad" length="middle"/>
<pin name="P$2" x="-20.32" y="17.78" visible="pad" length="middle"/>
<pin name="P$3" x="-20.32" y="12.7" visible="pad" length="middle"/>
<pin name="P$4" x="-20.32" y="7.62" visible="pad" length="middle"/>
<pin name="P$5" x="-20.32" y="2.54" visible="pad" length="middle"/>
<pin name="P$6" x="-20.32" y="-2.54" visible="pad" length="middle"/>
<pin name="P$7" x="-20.32" y="-7.62" visible="pad" length="middle"/>
<pin name="P$8" x="-20.32" y="-12.7" visible="pad" length="middle"/>
<pin name="P$9" x="-20.32" y="-17.78" visible="pad" length="middle"/>
<pin name="P$10" x="-20.32" y="-22.86" visible="pad" length="middle"/>
<pin name="P$11" x="20.32" y="-22.86" visible="pad" length="middle" rot="R180"/>
<pin name="P$12" x="20.32" y="-17.78" visible="pad" length="middle" rot="R180"/>
<pin name="P$13" x="20.32" y="-12.7" visible="pad" length="middle" rot="R180"/>
<pin name="P$14" x="20.32" y="-7.62" visible="pad" length="middle" rot="R180"/>
<pin name="P$15" x="20.32" y="-2.54" visible="pad" length="middle" rot="R180"/>
<pin name="P$16" x="20.32" y="2.54" visible="pad" length="middle" rot="R180"/>
<pin name="P$17" x="20.32" y="7.62" visible="pad" length="middle" rot="R180"/>
<pin name="P$18" x="20.32" y="12.7" visible="pad" length="middle" rot="R180"/>
<pin name="P$19" x="20.32" y="17.78" visible="pad" length="middle" rot="R180"/>
<pin name="P$20" x="20.32" y="22.86" visible="pad" length="middle" rot="R180"/>
<text x="-6.35" y="27.94" size="1.27" layer="94">MSP430G2553IN20</text>
<text x="-15.24" y="31.75" size="1.27" layer="94">&gt;NAME</text>
<text x="-12.7" y="22.86" size="1.27" layer="94">DVCC</text>
<text x="10.16" y="22.86" size="1.27" layer="94">DVSS</text>
<text x="-12.7" y="17.78" size="1.27" layer="94">P1.0</text>
<text x="-12.7" y="12.7" size="1.27" layer="94">P1.1</text>
<text x="-12.7" y="7.62" size="1.27" layer="94">P1.2</text>
<text x="-12.7" y="2.54" size="1.27" layer="94">P1.3</text>
<text x="-12.7" y="-2.54" size="1.27" layer="94">P1.4</text>
<text x="-12.7" y="-7.62" size="1.27" layer="94">P1.5</text>
<text x="10.16" y="-7.62" size="1.27" layer="94">P1.6</text>
<text x="10.16" y="-2.54" size="1.27" layer="94">P1.7</text>
<text x="-12.7" y="-12.7" size="1.27" layer="94">P2.0</text>
<text x="-12.7" y="-17.78" size="1.27" layer="94">P2.1</text>
<text x="-12.7" y="-22.86" size="1.27" layer="94">P2.2</text>
<text x="10.16" y="-22.86" size="1.27" layer="94">P2.3</text>
<text x="10.16" y="-17.78" size="1.27" layer="94">P2.4</text>
<text x="10.16" y="-12.7" size="1.27" layer="94">P2.5</text>
<text x="10.16" y="2.54" size="1.27" layer="94">/RST</text>
<text x="10.16" y="7.62" size="1.27" layer="94">TEST</text>
<text x="10.16" y="12.7" size="1.27" layer="94">P2.7</text>
<text x="10.16" y="17.78" size="1.27" layer="94">P2.6</text>
<text x="7.62" y="19.05" size="1.27" layer="94">XIN</text>
<text x="7.62" y="13.97" size="1.27" layer="94">XOUT</text>
</symbol>
<symbol name="SI4663F30">
<wire x1="0" y1="0" x2="0" y2="-45.72" width="0.254" layer="94"/>
<wire x1="0" y1="-45.72" x2="27.94" y2="-45.72" width="0.254" layer="94"/>
<wire x1="27.94" y1="-45.72" x2="27.94" y2="0" width="0.254" layer="94"/>
<wire x1="27.94" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<text x="10.16" y="-25.4" size="1.27" layer="94">Si4663F30</text>
<text x="0" y="1.27" size="1.27" layer="94">&gt;NAME</text>
<circle x="2.54" y="-2.54" radius="1.27" width="0.254" layer="94"/>
<text x="2.54" y="-7.62" size="1.27" layer="94">ANT</text>
<text x="2.54" y="-12.7" size="1.27" layer="94">GND</text>
<text x="22.86" y="-17.78" size="1.27" layer="94">NC</text>
<text x="22.86" y="-22.86" size="1.27" layer="94">NC</text>
<text x="22.86" y="-27.94" size="1.27" layer="94">SDN</text>
<text x="22.86" y="-33.02" size="1.27" layer="94">nIRQ</text>
<text x="22.86" y="-38.1" size="1.27" layer="94">nSEL</text>
<text x="22.86" y="-43.18" size="1.27" layer="94">GND</text>
<text x="22.86" y="-7.62" size="1.27" layer="94">VCC</text>
<text x="22.86" y="-12.7" size="1.27" layer="94">GND</text>
<text x="2.54" y="-17.78" size="1.27" layer="94">NC</text>
<text x="2.54" y="-22.86" size="1.27" layer="94">GPIO0</text>
<text x="2.54" y="-27.94" size="1.27" layer="94">GPIO1</text>
<text x="2.54" y="-33.02" size="1.27" layer="94">SDO</text>
<text x="2.54" y="-38.1" size="1.27" layer="94">SDI</text>
<text x="2.54" y="-43.18" size="1.27" layer="94">SCLK</text>
<pin name="P$1" x="-5.08" y="-7.62" visible="pad" length="middle"/>
<pin name="P$2" x="-5.08" y="-12.7" visible="pad" length="middle"/>
<pin name="P$3" x="-5.08" y="-17.78" visible="pad" length="middle"/>
<pin name="P$4" x="-5.08" y="-22.86" visible="pad" length="middle"/>
<pin name="P$5" x="-5.08" y="-27.94" visible="pad" length="middle"/>
<pin name="P$6" x="-5.08" y="-33.02" visible="pad" length="middle"/>
<pin name="P$7" x="-5.08" y="-38.1" visible="pad" length="middle"/>
<pin name="P$8" x="-5.08" y="-43.18" visible="pad" length="middle"/>
<pin name="P$9" x="33.02" y="-43.18" visible="pad" length="middle" rot="R180"/>
<pin name="P$10" x="33.02" y="-38.1" visible="pad" length="middle" rot="R180"/>
<pin name="P$11" x="33.02" y="-33.02" visible="pad" length="middle" rot="R180"/>
<pin name="P$12" x="33.02" y="-27.94" visible="pad" length="middle" rot="R180"/>
<pin name="P$13" x="33.02" y="-22.86" visible="pad" length="middle" rot="R180"/>
<pin name="P$14" x="33.02" y="-17.78" visible="pad" length="middle" rot="R180"/>
<pin name="P$15" x="33.02" y="-12.7" visible="pad" length="middle" rot="R180"/>
<pin name="P$16" x="33.02" y="-7.62" visible="pad" length="middle" rot="R180"/>
</symbol>
<symbol name="ANTENNA">
<wire x1="0" y1="0" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="5.08" width="0.254" layer="94"/>
<pin name="P$1" x="0" y="0" visible="pin" length="point"/>
<text x="-1.27" y="6.35" size="0.6096" layer="94">Antenna</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="MSP430G2553IN20">
<gates>
<gate name="G$1" symbol="MSP430G2553IN20" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DIP762W53P254L2215H508Q20B">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$10" pad="10"/>
<connect gate="G$1" pin="P$11" pad="11"/>
<connect gate="G$1" pin="P$12" pad="12"/>
<connect gate="G$1" pin="P$13" pad="13"/>
<connect gate="G$1" pin="P$14" pad="14"/>
<connect gate="G$1" pin="P$15" pad="15"/>
<connect gate="G$1" pin="P$16" pad="16"/>
<connect gate="G$1" pin="P$17" pad="17"/>
<connect gate="G$1" pin="P$18" pad="18"/>
<connect gate="G$1" pin="P$19" pad="19"/>
<connect gate="G$1" pin="P$2" pad="2"/>
<connect gate="G$1" pin="P$20" pad="20"/>
<connect gate="G$1" pin="P$3" pad="3"/>
<connect gate="G$1" pin="P$4" pad="4"/>
<connect gate="G$1" pin="P$5" pad="5"/>
<connect gate="G$1" pin="P$6" pad="6"/>
<connect gate="G$1" pin="P$7" pad="7"/>
<connect gate="G$1" pin="P$8" pad="8"/>
<connect gate="G$1" pin="P$9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:13336042/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="SI4663F30">
<description>1W Long Range RF Module from NiceRF.
&lt;B&gt;Si4663F30&lt;/B&gt;</description>
<gates>
<gate name="G$1" symbol="SI4663F30" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SI4663F30">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$10" pad="P$10"/>
<connect gate="G$1" pin="P$11" pad="P$11"/>
<connect gate="G$1" pin="P$12" pad="P$12"/>
<connect gate="G$1" pin="P$13" pad="P$13"/>
<connect gate="G$1" pin="P$14" pad="P$14"/>
<connect gate="G$1" pin="P$15" pad="P$15"/>
<connect gate="G$1" pin="P$16" pad="P$16"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
<connect gate="G$1" pin="P$3" pad="P$3"/>
<connect gate="G$1" pin="P$4" pad="P$4"/>
<connect gate="G$1" pin="P$5" pad="P$5"/>
<connect gate="G$1" pin="P$6" pad="P$6"/>
<connect gate="G$1" pin="P$7" pad="P$7"/>
<connect gate="G$1" pin="P$8" pad="P$8"/>
<connect gate="G$1" pin="P$9" pad="P$9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SI4663F30-3D" package="INDCAV400P3800X2000X400-16N">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$10" pad="10"/>
<connect gate="G$1" pin="P$11" pad="11"/>
<connect gate="G$1" pin="P$12" pad="12"/>
<connect gate="G$1" pin="P$13" pad="13"/>
<connect gate="G$1" pin="P$14" pad="14"/>
<connect gate="G$1" pin="P$15" pad="15"/>
<connect gate="G$1" pin="P$16" pad="16"/>
<connect gate="G$1" pin="P$2" pad="2"/>
<connect gate="G$1" pin="P$3" pad="3"/>
<connect gate="G$1" pin="P$4" pad="4"/>
<connect gate="G$1" pin="P$5" pad="5"/>
<connect gate="G$1" pin="P$6" pad="6"/>
<connect gate="G$1" pin="P$7" pad="7"/>
<connect gate="G$1" pin="P$8" pad="8"/>
<connect gate="G$1" pin="P$9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:13333453/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ANTENNA">
<gates>
<gate name="G$1" symbol="ANTENNA" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ANTENNA">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="Phase_2" deviceset="MSP430G2553IN20" device="" package3d_urn="urn:adsk.eagle:package:13336042/1"/>
<part name="U$2" library="Phase_2" deviceset="SI4663F30" device="SI4663F30-3D" package3d_urn="urn:adsk.eagle:package:13333453/1"/>
<part name="U$3" library="Phase_2" deviceset="ANTENNA" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="35.56" y="-15.24" smashed="yes">
<attribute name="NAME" x="20.32" y="16.51" size="1.27" layer="94"/>
</instance>
<instance part="U$2" gate="G$1" x="-50.8" y="53.34" smashed="yes">
<attribute name="NAME" x="-50.8" y="54.61" size="1.27" layer="94"/>
</instance>
<instance part="U$3" gate="G$1" x="-58.42" y="45.72" smashed="yes"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="P$16"/>
<pinref part="U$1" gate="G$1" pin="P$1"/>
<wire x1="-17.78" y1="45.72" x2="15.24" y2="45.72" width="0.1524" layer="91"/>
<wire x1="15.24" y1="45.72" x2="15.24" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="P$1"/>
<pinref part="U$2" gate="G$1" pin="P$1"/>
<wire x1="-58.42" y1="45.72" x2="-55.88" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="P$15"/>
<pinref part="U$1" gate="G$1" pin="P$20"/>
<wire x1="-17.78" y1="40.64" x2="-2.54" y2="40.64" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="40.64" x2="12.7" y2="40.64" width="0.1524" layer="91"/>
<wire x1="12.7" y1="40.64" x2="55.88" y2="40.64" width="0.1524" layer="91"/>
<wire x1="55.88" y1="40.64" x2="55.88" y2="7.62" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="P$9"/>
<wire x1="-17.78" y1="10.16" x2="12.7" y2="10.16" width="0.1524" layer="91"/>
<wire x1="12.7" y1="10.16" x2="12.7" y2="40.64" width="0.1524" layer="91"/>
<junction x="12.7" y="40.64"/>
<pinref part="U$2" gate="G$1" pin="P$2"/>
<wire x1="-55.88" y1="40.64" x2="-63.5" y2="40.64" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="40.64" x2="-63.5" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="60.96" x2="-2.54" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="60.96" x2="-2.54" y2="40.64" width="0.1524" layer="91"/>
<junction x="-2.54" y="40.64"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
