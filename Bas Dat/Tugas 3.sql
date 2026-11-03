INSERT INTO lokomotif (ID_Lokomotif, Tipe_Lokomotif, No_Lokomotif, Tahun_Pembuatan, Dipo_Induk) VALUES
("LOK006", "CC201", "CC201-21-14", "2021", "Dipo Cipinang"),
("LOK007", "CC203", "CC203-21-25", "2021", "Dipo Yogyakarta"),
("LOK008", "CC201", "CC201-22-09", "2022", "Dipo Purwokerto"),
("LOK009", "CC206", "CC206-22-18", "2022", "Dipo Cipinang"),
("LOK010", "CC203", "CC203-23-04", "2023", "Dipo Bandung"),
("LOK011", "CC206", "CC206-23-07", "2023", "Dipo Bandung"),
("LOK012", "CC206", "CC206-24-12", "2024", "Dipo Yogyakarta"),
("LOK013", "CC201", "CC201-25-03", "2025", "Dipo Cipinang"),
("LOK014", "CC203", "CC203-25-16", "2025", "Dipo Purwokerto"),
("LOK015", "CC206", "CC206-26-05", "2026", "Dipo Bandung");

INSERT INTO stasiun (ID_Stasiun, Nama_Stasiun, Kota, Lokasi) VALUES
("CN" , "Cirebon (CN)", "Cirebon", "Jl. Inspeksi, Kebonbaru, Kejaksan, Kota Cirebon"),
("CKP", "Cikampek (CKP)", "Karawang", "Jl. Stasiun, Cikampek Kota, Cikampek, Karawang"),
("KW" , "Karawang (KW)", "Karawang", "Jl. Ahmad Yani, Karawang Wetan, Karawang Timur, Karawang"),
("BKS", "Bekasi (BKS)", "Bekasi", "Jl. Ir. H. Juanda, Margahayu, Bekasi Timur, Kota Bekasi"),
("JNG", "Jatinegara (JNG)", "Jakarta Timur", "Jl. Jatinegara Barat, Bali Mester, Jatinegara, Jakarta Timur"),
("PSE", "Pasar Senen (PSE)", "Jakarta Pusat", "Jl. Stasiun Senen, Senen, Jakarta Pusat"),
("GMR", "Gambir (GMR)", "Jakarta Pusat", "Jl. Medan Merdeka Timur, Gambir, Jakarta Pusat"),
("PWK", "Purwakarta (PWK)", "Purwakarta", "Jl. Ipik Gandamanah, Nagri Kaler, Purwakarta"),
("CMI", "Cimahi (CMI)", "Cimahi", "Jl. Stasiun Cimahi, Padasuka, Cimahi Tengah, Kota Cimahi"),
("BD" , "Bandung (BD)", "Bandung", "Jl. Kebon Kawung No. 43, Pasir Kaliki, Cicendo, Kota Bandung"),
("BMA", "Bumiayu (BMA)", "Brebes", "Jl. Stasiun, Dukuhturi, Bumiayu, Brebes");

INSERT INTO kereta_api (ID_Kereta, Nama_Kereta, Kelas_Kereta, Daop) VALUES
("KA006", "Joglosemarkerto", "Eksekutif dan Ekonomi", "Daop 6 Yogyakarta"),
("KA007", "Argo Dwipangga", "Luxury dan Eksekutif", "Daop 6 Yogyakarta"),
("KA008", "Argo Semeru", "Luxury dan Eksekutif", "Daop 1 Jakarta"),
("KA009", "Argo Parahyangan", "Eksekutif dan Ekonomi", "Daop 2 Bandung"),
("KA010", "Cakrabuana", "Ekonomi", "Daop 5 Purwokerto"),
("KA011", "Manahan", "Eksekutif dan Ekonomi", "Daop 6 Yogyakarta"),
("KA012", "Gajayana", "Luxury dan Eksekutif", "Daop 1 Jakarta"),
("KA013", "Bima", "Luxury dan Eksekutif", "Daop 1 Jakarta"),
("KA014", "Fajar Utama Solo", "Eksekutif dan Ekonomi", "Daop 6 Yogyakarta"),
("KA015", "Senja Utama Solo", "Eksekutif dan Ekonomi", "Daop 6 Yogyakarta");

INSERT INTO gerbong (ID_Gerbong, Kelas_Gerbong, No_Gerbong, Jumlah_Kursi) VALUES
('GRB031', 'Eksekutif', 'K1 0 24 11 BD', 50),
('GRB032', 'Eksekutif', 'K1 0 24 12 BD', 50),
('GRB033', 'Ekonomi'  , 'K3 0 24 13 BD', 80),
('GRB034', 'Ekonomi'  , 'K3 0 24 14 BD', 80),
('GRB035', 'Ekonomi'  , 'K3 0 24 15 BD', 80),
('GRB036', 'Eksekutif', 'K1 0 25 01 JAKK', 50),
('GRB037', 'Eksekutif', 'K1 0 25 02 JAKK', 50),
('GRB038', 'Eksekutif', 'K1 0 25 03 JAKK', 50),
('GRB039', 'Eksekutif', 'K1 0 25 04 JAKK', 50),
('GRB040', 'Eksekutif', 'K1 0 25 05 JAKK', 50),
('GRB041', 'Ekonomi'  , 'K3 0 25 06 JAKK', 80),
('GRB042', 'Ekonomi'  , 'K3 0 25 07 JAKK', 80),
('GRB043', 'Ekonomi'  , 'K3 0 25 08 JAKK', 80),
('GRB044', 'Ekonomi'  , 'K3 0 25 09 JAKK', 80),
('GRB045', 'Ekonomi'  , 'K3 0 25 10 JAKK', 80),
('GRB046', 'Eksekutif', 'K1 0 26 01 JAKK', 50),
('GRB047', 'Eksekutif', 'K1 0 26 02 JAKK', 50),
('GRB048', 'Eksekutif', 'K1 0 26 03 JAKK', 50),
('GRB049', 'Eksekutif', 'K1 0 26 04 JAKK', 50),
('GRB050', 'Eksekutif', 'K1 0 26 05 JAKK', 50);

INSERT INTO jadwal_perjalanan (ID_Jadwal, ID_Kereta, Hari_Jadwal, Kategori_Jadwal, Status_Jadwal, Jam_Keberangkatan_Awal, Jam_Kedatangan_Akhir) VALUES
('JDW008', 'KA006', 'Senin'  , 'Reguler', 'Aktif', '06:10:00', '10:07:00'),
('JDW009', 'KA007', 'Selasa' , 'Reguler', 'Aktif', '20:35:00', '03:30:00'),
('JDW010', 'KA008', 'Rabu'   , 'Reguler', 'Aktif', '06:20:00', '13:30:00'),
('JDW011', 'KA009', 'Kamis'  , 'Reguler', 'Aktif', '07:30:00', '10:22:00'),
('JDW012', 'KA010', 'Jum\'at', 'Reguler', 'Aktif', '05:30:00', '10:24:00'),
('JDW013', 'KA011', 'Sabtu'  , 'Reguler', 'Aktif', '09:50:00', '17:31:00'),
('JDW014', 'KA012', 'Minggu' , 'Reguler', 'Aktif', '18:50:00', '02:11:00'),
('JDW015', 'KA013', 'Senin'  , 'Reguler', 'Aktif', '17:00:00', '00:10:00'),
('JDW016', 'KA014', 'Selasa' , 'Reguler', 'Aktif', '05:40:00', '13:25:00'),
('JDW017', 'KA015', 'Selasa' , 'Reguler', 'Aktif', '18:55:00', '02:51:00');

INSERT INTO rute (ID_Rute, ID_Jadwal, ID_Stasiun, Urutan_Stasiun) VALUES
-- JDW008: Joglosemarkerto
('RUT031', 'JDW008', 'SLO', 1),
('RUT032', 'JDW008', 'KT' , 2),
('RUT033', 'JDW008', 'YK' , 3),
('RUT034', 'JDW008', 'KTA', 4),
('RUT035', 'JDW008', 'KM' , 5),
('RUT036', 'JDW008', 'GB' , 6),
('RUT037', 'JDW008', 'KYA', 7),
('RUT038', 'JDW008', 'PWT', 8),
-- JDW009: Argo Dwipangga
('RUT039', 'JDW009', 'SLO', 1),
('RUT040', 'JDW009', 'KT' , 2),
('RUT041', 'JDW009', 'YK' , 3),
('RUT042', 'JDW009', 'PWT', 4),
('RUT043', 'JDW009', 'CN' , 5),
('RUT044', 'JDW009', 'GMR', 6),
-- JDW010: Argo Semeru
('RUT045', 'JDW010', 'GMR', 1),
('RUT046', 'JDW010', 'BKS', 2),
('RUT047', 'JDW010', 'CN' , 3),
('RUT048', 'JDW010', 'PWT', 4),
('RUT049', 'JDW010', 'KYA', 5),
('RUT050', 'JDW010', 'KM' , 6),
('RUT051', 'JDW010', 'KTA', 7),
('RUT052', 'JDW010', 'YK' , 8),
('RUT053', 'JDW010', 'SLO', 9),
-- JDW011: Argo Parahyangan
('RUT054', 'JDW011', 'GMR', 1),
('RUT055', 'JDW011', 'JNG', 2),
('RUT056', 'JDW011', 'BKS', 3),
('RUT057', 'JDW011', 'KW' , 4),
('RUT058', 'JDW011', 'PWK', 5),
('RUT059', 'JDW011', 'CMI', 6),
('RUT060', 'JDW011', 'BD' , 7),
-- JDW012: Cakrabuana
('RUT061', 'JDW012', 'PWT', 1),
('RUT062', 'JDW012', 'BMA', 2),
('RUT063', 'JDW012', 'CN' , 3),
('RUT064', 'JDW012', 'CKP', 4),
('RUT065', 'JDW012', 'BKS', 5),
('RUT066', 'JDW012', 'GMR', 6),
-- JDW013: Manahan
('RUT067', 'JDW013', 'SLO', 1),
('RUT068', 'JDW013', 'KT' , 2),
('RUT069', 'JDW013', 'YK' , 3),
('RUT070', 'JDW013', 'KTA', 4),
('RUT071', 'JDW013', 'KM' , 5),
('RUT072', 'JDW013', 'KYA', 6),
('RUT073', 'JDW013', 'PWT', 7),
('RUT074', 'JDW013', 'CN' , 8),
('RUT075', 'JDW013', 'GMR', 9),
-- JDW014: Gajayana
('RUT076', 'JDW014', 'GMR', 1),
('RUT077', 'JDW014', 'JNG', 2),
('RUT078', 'JDW014', 'BKS', 3),
('RUT079', 'JDW014', 'CN' , 4),
('RUT080', 'JDW014', 'PWT', 5),
('RUT081', 'JDW014', 'KYA', 6),
('RUT082', 'JDW014', 'KM' , 7),
('RUT083', 'JDW014', 'KTA', 8),
('RUT084', 'JDW014', 'YK' , 9),
('RUT085', 'JDW014', 'SLO', 10),
-- JDW015: Bima
('RUT086', 'JDW015', 'GMR', 1),
('RUT087', 'JDW015', 'BKS', 2),
('RUT088', 'JDW015', 'CN' , 3),
('RUT089', 'JDW015', 'PWT', 4),
('RUT090', 'JDW015', 'KYA', 5),
('RUT091', 'JDW015', 'KM' , 6),
('RUT092', 'JDW015', 'KTA', 7),
('RUT093', 'JDW015', 'YK' , 8),
('RUT094', 'JDW015', 'SLO', 9),
-- JDW016: Fajar Utama Solo
('RUT095', 'JDW016', 'PSE', 1),
('RUT096', 'JDW016', 'JNG', 2),
('RUT097', 'JDW016', 'BKS', 3),
('RUT098', 'JDW016', 'KW' , 4),
('RUT099', 'JDW016', 'CN' , 5),
('RUT100', 'JDW016', 'PWT', 6),
('RUT101', 'JDW016', 'KYA', 7),
('RUT102', 'JDW016', 'KM' , 8),
('RUT103', 'JDW016', 'KTA', 9),
('RUT104', 'JDW016', 'WT' , 10),
('RUT105', 'JDW016', 'YK' , 11),
('RUT106', 'JDW016', 'KT' , 12),
('RUT107', 'JDW016', 'SLO', 13),
-- JDW017: Senja Utama Solo
('RUT108', 'JDW017', 'SLO', 1),
('RUT109', 'JDW017', 'KT' , 2),
('RUT110', 'JDW017', 'YK' , 3),
('RUT111', 'JDW017', 'WT' , 4),
('RUT112', 'JDW017', 'KTA', 5),
('RUT113', 'JDW017', 'KM' , 6),
('RUT114', 'JDW017', 'KYA', 7),
('RUT115', 'JDW017', 'PWT', 8),
('RUT116', 'JDW017', 'CN' , 9),
('RUT117', 'JDW017', 'KW' , 10),
('RUT118', 'JDW017', 'BKS', 11),
('RUT119', 'JDW017', 'JNG', 12),
('RUT120', 'JDW017', 'PSE', 13);

INSERT INTO rangkaian (ID_Rangkaian, ID_Kereta, ID_Gerbong, Posisi_Gerbong) VALUES
-- KA006: Joglosemarkerto (Eksekutif dan Ekonomi)
('RGK026', 'KA006', 'GRB004', 1),
('RGK027', 'KA006', 'GRB005', 2),
('RGK028', 'KA006', 'GRB017', 3),
('RGK029', 'KA006', 'GRB018', 4),
('RGK030', 'KA006', 'GRB019', 5),
-- KA007: Argo Dwipangga (Luxury dan Eksekutif)
('RGK031', 'KA007', 'GRB006', 1),
('RGK032', 'KA007', 'GRB007', 2),
('RGK033', 'KA007', 'GRB036', 3),
('RGK034', 'KA007', 'GRB037', 4),
('RGK035', 'KA007', 'GRB038', 5),
-- KA008: Argo Semeru (Luxury dan Eksekutif)
('RGK036', 'KA008', 'GRB008', 1),
('RGK037', 'KA008', 'GRB009', 2),
('RGK038', 'KA008', 'GRB039', 3),
('RGK039', 'KA008', 'GRB040', 4),
('RGK040', 'KA008', 'GRB046', 5),
-- KA009: Argo Parahyangan (Eksekutif dan Ekonomi)
('RGK041', 'KA009', 'GRB031', 1),
('RGK042', 'KA009', 'GRB032', 2),
('RGK043', 'KA009', 'GRB033', 3),
('RGK044', 'KA009', 'GRB034', 4),
('RGK045', 'KA009', 'GRB035', 5),
-- KA010: Cakrabuana (Ekonomi)
('RGK046', 'KA010', 'GRB041', 1),
('RGK047', 'KA010', 'GRB042', 2),
('RGK048', 'KA010', 'GRB043', 3),
('RGK049', 'KA010', 'GRB044', 4),
('RGK050', 'KA010', 'GRB045', 5),
-- KA011: Manahan (Eksekutif dan Ekonomi)
('RGK051', 'KA011', 'GRB025', 1),
('RGK052', 'KA011', 'GRB021', 2),
('RGK053', 'KA011', 'GRB020', 3),
('RGK054', 'KA011', 'GRB026', 4),
('RGK055', 'KA011', 'GRB027', 5),
-- KA012: Gajayana (Luxury dan Eksekutif)
('RGK056', 'KA012', 'GRB010', 1),
('RGK057', 'KA012', 'GRB006', 2),
('RGK058', 'KA012', 'GRB047', 3),
('RGK059', 'KA012', 'GRB048', 4),
('RGK060', 'KA012', 'GRB049', 5),
-- KA013: Bima (Luxury dan Eksekutif)
('RGK061', 'KA013', 'GRB009', 1),
('RGK062', 'KA013', 'GRB010', 2),
('RGK063', 'KA013', 'GRB050', 3),
('RGK064', 'KA013', 'GRB011', 4),
('RGK065', 'KA013', 'GRB012', 5),
-- KA014: Fajar Utama Solo (Eksekutif dan Ekonomi)
('RGK066', 'KA014', 'GRB022', 1),
('RGK067', 'KA014', 'GRB023', 2),
('RGK068', 'KA014', 'GRB028', 3),
('RGK069', 'KA014', 'GRB029', 4),
('RGK070', 'KA014', 'GRB030', 5),
-- KA015: Senja Utama Solo (Eksekutif dan Ekonomi)
('RGK071', 'KA015', 'GRB022', 1),
('RGK072', 'KA015', 'GRB023', 2),
('RGK073', 'KA015', 'GRB028', 3),
('RGK074', 'KA015', 'GRB029', 4),
('RGK075', 'KA015', 'GRB030', 5);

INSERT INTO dinas (ID_Dinas, ID_Masinis, ID_Lokomotif, ID_Jadwal, Peran_Masinis, Tanggal) VALUES
('DNS015', 'MSN001', 'LOK006', 'JDW008', 'Masinis Utama'  , '2026-10-05'),
('DNS016', 'MSN009', 'LOK006', 'JDW008', 'Masinis Asisten', '2026-10-05'),
('DNS017', 'MSN002', 'LOK007', 'JDW009', 'Masinis Utama'  , '2026-10-06'),
('DNS018', 'MSN010', 'LOK007', 'JDW009', 'Masinis Asisten', '2026-10-06'),
('DNS019', 'MSN003', 'LOK008', 'JDW010', 'Masinis Utama'  , '2026-10-07'),
('DNS020', 'MSN011', 'LOK008', 'JDW010', 'Masinis Asisten', '2026-10-07'),
('DNS021', 'MSN004', 'LOK009', 'JDW011', 'Masinis Utama'  , '2026-10-08'),
('DNS022', 'MSN012', 'LOK009', 'JDW011', 'Masinis Asisten', '2026-10-08'),
('DNS023', 'MSN005', 'LOK010', 'JDW012', 'Masinis Utama'  , '2026-10-09'),
('DNS024', 'MSN013', 'LOK010', 'JDW012', 'Masinis Asisten', '2026-10-09'),
('DNS025', 'MSN006', 'LOK011', 'JDW013', 'Masinis Utama'  , '2026-10-10'),
('DNS026', 'MSN014', 'LOK011', 'JDW013', 'Masinis Asisten', '2026-10-10'),
('DNS027', 'MSN007', 'LOK012', 'JDW014', 'Masinis Utama'  , '2026-10-11'),
('DNS028', 'MSN015', 'LOK012', 'JDW014', 'Masinis Asisten', '2026-10-11'),
('DNS029', 'MSN008', 'LOK013', 'JDW015', 'Masinis Utama'  , '2026-10-12'),
('DNS030', 'MSN009', 'LOK013', 'JDW015', 'Masinis Asisten', '2026-10-12'),
('DNS031', 'MSN001', 'LOK014', 'JDW016', 'Masinis Utama'  , '2026-10-13'),
('DNS032', 'MSN010', 'LOK014', 'JDW016', 'Masinis Asisten', '2026-10-13'),
('DNS033', 'MSN002', 'LOK015', 'JDW017', 'Masinis Utama'  , '2026-10-14'),
('DNS034', 'MSN011', 'LOK015', 'JDW017', 'Masinis Asisten', '2026-10-14');

ALTER TABLE masinis
MODIFY NIK VARCHAR(16) NOT NULL UNIQUE,
MODIFY Nama_Masinis VARCHAR(100) NOT NULL,
MODIFY Email VARCHAR(255) UNIQUE;

ALTER TABLE lokomotif
MODIFY Tipe_Lokomotif VARCHAR(10) NOT NULL,
MODIFY No_Lokomotif VARCHAR(20) NOT NULL UNIQUE;

ALTER TABLE stasiun
MODIFY Nama_Stasiun VARCHAR(20) NOT NULL;

ALTER TABLE kereta_api
MODIFY Nama_Kereta VARCHAR(100) NOT NULL;

ALTER TABLE gerbong
MODIFY Kelas_Gerbong VARCHAR(20) NOT NULL,
MODIFY No_Gerbong VARCHAR(20) NOT NULL;

ALTER TABLE jadwal_perjalanan
MODIFY ID_Kereta VARCHAR(20) NOT NULL,
MODIFY Hari_Jadwal VARCHAR(20) NOT NULL,
MODIFY Kategori_Jadwal VARCHAR(20) DEFAULT 'Reguler',
MODIFY Status_Jadwal VARCHAR(20) DEFAULT 'Aktif',
MODIFY Jam_Keberangkatan_Awal TIME NOT NULL,
MODIFY Jam_Kedatangan_Akhir TIME NOT NULL,
ADD CONSTRAINT fkKeretaJadwal FOREIGN KEY (ID_Kereta) REFERENCES kereta_api (ID_Kereta)
ON UPDATE CASCADE ON DELETE RESTRICT;

ALTER TABLE rute
MODIFY ID_Jadwal VARCHAR(20) NOT NULL,
MODIFY ID_Stasiun VARCHAR(20) NOT NULL,
MODIFY Urutan_Stasiun INT(11) NOT NULL,
ADD CONSTRAINT fkJadwalRute FOREIGN KEY (ID_Jadwal) REFERENCES jadwal_perjalanan (ID_Jadwal)
ON UPDATE CASCADE ON DELETE RESTRICT,
ADD CONSTRAINT fkStasiunRute FOREIGN KEY (ID_Stasiun) REFERENCES stasiun (ID_Stasiun)
ON UPDATE CASCADE ON DELETE RESTRICT;

ALTER TABLE rangkaian
MODIFY ID_Kereta VARCHAR(20) NOT NULL,
MODIFY ID_Gerbong VARCHAR(20) NOT NULL,
MODIFY Posisi_Gerbong INT(11) NOT NULL,
ADD CONSTRAINT fkKeretaRangkaian FOREIGN KEY (ID_Kereta) REFERENCES kereta_api (ID_Kereta)
ON UPDATE CASCADE ON DELETE RESTRICT,
ADD CONSTRAINT fkGerbongRangkaian FOREIGN KEY (ID_Gerbong) REFERENCES gerbong (ID_Gerbong)
ON UPDATE CASCADE ON DELETE RESTRICT;

ALTER TABLE dinas
MODIFY ID_Masinis VARCHAR(20) NOT NULL,
MODIFY ID_Lokomotif VARCHAR(20) NOT NULL,
MODIFY ID_Jadwal VARCHAR(20) NOT NULL,
MODIFY Peran_Masinis VARCHAR(20) NOT NULL,
MODIFY Tanggal DATE NOT NULL,
ADD CONSTRAINT fkMasinisDinas FOREIGN KEY (ID_Masinis) REFERENCES masinis (ID_Masinis)
ON UPDATE CASCADE ON DELETE RESTRICT,
ADD CONSTRAINT fkLokomotifDinas FOREIGN KEY (ID_Lokomotif) REFERENCES lokomotif (ID_Lokomotif)
ON UPDATE CASCADE ON DELETE RESTRICT,
ADD CONSTRAINT fkJadwalDinas FOREIGN KEY (ID_Jadwal) REFERENCES jadwal_perjalanan (ID_Jadwal)
ON UPDATE CASCADE ON DELETE RESTRICT;

Masinis

SELECT * FROM masinis
   WHERE Alamat LIKE '%Yogyakarta%';

SELECT * FROM masinis
   WHERE Alamat LIKE '%Solo' AND NIK LIKE '3372%';

SELECT * FROM masinis
   WHERE Alamat LIKE '%Banyumas' OR Alamat LIKE '%Solo';

SELECT * FROM masinis
   WHERE NOT Alamat LIKE '%Yogyakarta';

SELECT ID_Masinis, Nama_Masinis, Alamat FROM masinis
   ORDER BY Nama_Masinis ASC;

Lokomotif

SELECT * FROM lokomotif
   WHERE Tahun_Pembuatan > 2021;

SELECT * FROM lokomotif
   WHERE Tipe_Lokomotif = 'CC206' AND Dipo_Induk = 'Dipo Bandung';

SELECT * FROM lokomotif
   WHERE Tipe_Lokomotif = 'CC201' OR Tahun_Pembuatan = 2025;

SELECT * FROM lokomotif
   WHERE NOT Tipe_Lokomotif = 'CC201' AND NOT Dipo_Induk = 'Dipo Yogyakarta';

SELECT Dipo_Induk, COUNT(*) AS Banyak_Lokomotif FROM lokomotif
   GROUP BY Dipo_Induk;

SELECT * FROM lokomotif
   ORDER BY Tahun_Pembuatan DESC;

SELECT Dipo_Induk, COUNT(*) AS Banyak_Lokomotif FROM lokomotif
   GROUP BY Dipo_Induk
   HAVING COUNT(*) > 3;

SELECT Tipe_Lokomotif, COUNT(*) AS Banyak_Lokomotif FROM lokomotif
   WHERE Tahun_Pembuatan BETWEEN 2020 AND 2026 AND NOT Dipo_Induk = 'Dipo Cipinang'
   GROUP BY Tipe_Lokomotif
   ORDER BY Banyak_Lokomotif DESC;

Stasiun

SELECT Nama_Stasiun, Lokasi FROM stasiun
   WHERE Lokasi LIKE '%Yogyakarta%';

SELECT Nama_Stasiun, Lokasi FROM stasiun
   WHERE Kota = 'Kebumen' AND Lokasi LIKE 'Jl.%';

SELECT Nama_Stasiun, Kota FROM stasiun
   WHERE Kota = 'Kebumen' OR Kota = 'Yogyakarta';

SELECT Nama_Stasiun, Lokasi FROM stasiun
   WHERE NOT Lokasi LIKE 'Jl.%';

SELECT Kota, COUNT(*) AS Banyak_Stasiun FROM stasiun
   GROUP BY Kota;

SELECT Kota, COUNT(*) AS Banyak_Stasiun FROM stasiun
   GROUP BY Kota
   ORDER BY Banyak_Stasiun DESC;

SELECT Kota, COUNT(*) AS Banyak_Stasiun FROM stasiun
   GROUP BY Kota
   HAVING COUNT(*) > 1;

SELECT Kota, COUNT(*) AS Banyak_Stasiun FROM stasiun
   GROUP BY Kota
   HAVING COUNT(*) > 1
   ORDER BY Banyak_Stasiun DESC;

Kereta_Api

SELECT Nama_Kereta, Kelas_Kereta FROM kereta_api
   WHERE Kelas_Kereta LIKE 'Luxury%';

SELECT Nama_Kereta, Kelas_Kereta, Daop FROM kereta_api
   WHERE Daop LIKE '%Yogyakarta' AND Kelas_Kereta LIKE 'Luxury%';

SELECT Nama_Kereta, Daop FROM kereta_api
   WHERE Daop LIKE '%Jakarta' OR Daop LIKE '%Purwokerto';

SELECT Nama_Kereta, Daop FROM kereta_api
   WHERE NOT Daop LIKE '%Yogyakarta';

SELECT Daop, COUNT(*) AS Banyak_Kereta FROM kereta_api
   GROUP BY Daop;

SELECT Nama_Kereta, Kelas_Kereta FROM kereta_api
   ORDER BY Nama_Kereta ASC;

SELECT Daop, COUNT(*) AS Banyak_Kereta FROM kereta_api
   GROUP BY Daop
   HAVING Banyak_Kereta > 1;

SELECT Daop, COUNT(*) AS Banyak_Kereta FROM kereta_api
   WHERE NOT Kelas_Kereta LIKE 'Luxury%'
   GROUP BY Daop
   HAVING Banyak_Kereta > 1
   ORDER BY Banyak_Kereta DESC;

Gerbong

SELECT No_Gerbong, Kelas_Gerbong FROM gerbong
   WHERE Kelas_Gerbong = 'Luxury';

SELECT No_Gerbong, Kelas_Gerbong FROM gerbong
   WHERE Kelas_Gerbong = 'Ekonomi' AND No_Gerbong LIKE '%JAKK';

SELECT No_Gerbong, Kelas_Gerbong FROM gerbong
   WHERE Kelas_Gerbong = 'Luxury' OR No_Gerbong LIKE '%26%';

SELECT No_Gerbong, Kelas_Gerbong FROM gerbong
   WHERE NOT No_Gerbong LIKE 'K3%' AND NOT No_Gerbong LIKE '%JAKK';

SELECT Kelas_Gerbong, COUNT(*) AS Banyak_Gerbong FROM gerbong
   GROUP BY Kelas_Gerbong;

SELECT Kelas_Gerbong, COUNT(*) AS Banyak_Gerbong FROM gerbong
   GROUP BY Kelas_Gerbong
   ORDER BY Banyak_Gerbong ASC;

SELECT Kelas_Gerbong, COUNT(*) AS Banyak_Gerbong FROM gerbong
   GROUP BY Kelas_Gerbong
   HAVING Banyak_Gerbong > 20;

SELECT Kelas_Gerbong, COUNT(*) AS Banyak_Gerbong FROM gerbong
   WHERE NOT No_Gerbong LIKE '%JAKK' AND NOT No_Gerbong LIKE '%BD'
   GROUP BY Kelas_Gerbong
   HAVING Banyak_Gerbong >= 10
   ORDER BY Banyak_Gerbong ASC;

Jadwal Perjalanan

SELECT ID_Kereta, Hari_Jadwal FROM jadwal_perjalanan
   WHERE Hari_Jadwal = 'Selasa';

SELECT ID_Kereta, Hari_Jadwal, Jam_Keberangkatan_Awal, Jam_Kedatangan_Akhir FROM jadwal_perjalanan
   WHERE Hari_Jadwal = 'Selasa' AND Jam_Keberangkatan_Awal BETWEEN '00:00:00' AND '06:00:00';

SELECT ID_Kereta, Hari_Jadwal, Jam_Keberangkatan_Awal, Jam_Kedatangan_Akhir FROM jadwal_perjalanan
   WHERE Hari_Jadwal = 'Senin' OR Jam_Keberangkatan_Awal BETWEEN '18:00:00' AND '23:59:59';

SELECT ID_Kereta, Hari_Jadwal, Jam_Keberangkatan_Awal, Jam_Kedatangan_Akhir FROM jadwal_perjalanan
   WHERE NOT Hari_Jadwal IN ('Senin','Selasa','Rabu');

SELECT Hari_Jadwal, COUNT(*) AS Banyak_Jadwal FROM jadwal_perjalanan
   GROUP BY Hari_Jadwal;

SELECT ID_Kereta, Hari_Jadwal, Jam_Keberangkatan_Awal, Jam_Kedatangan_Akhir FROM jadwal_perjalanan
   ORDER BY Jam_Keberangkatan_Awal ASC;

SELECT Hari_Jadwal, COUNT(*) AS Banyak_Jadwal FROM jadwal_perjalanan
   GROUP BY Hari_Jadwal
   HAVING Banyak_Jadwal > 2;

SELECT Hari_Jadwal, COUNT(*) AS Banyak_Jadwal FROM jadwal_perjalanan
   WHERE Jam_Keberangkatan_Awal BETWEEN '06:00:00' AND '18:00:00'
   GROUP BY Hari_Jadwal
   HAVING Banyak_Jadwal > 1
   ORDER BY Banyak_Jadwal ASC;

Rute

SELECT ID_Jadwal, ID_Stasiun FROM rute
   WHERE ID_Stasiun IN ('BD','BKS','PSE');

SELECT ID_Jadwal, ID_Stasiun FROM rute
   WHERE ID_Stasiun IN ('BD','BKS','PSE') AND ID_Jadwal IN ('JDW011','JDW017');

SELECT ID_Jadwal, ID_Stasiun FROM rute
   WHERE ID_Stasiun IN ('BD','PSE') OR ID_Jadwal IN ('JDW001','JDW005');

SELECT ID_Jadwal, ID_Stasiun FROM rute
   WHERE NOT ID_Jadwal IN ('JDW001','JDW003','JDW005','JDW007','JDW009','JDW011','JDW013','JDW015');

SELECT ID_Jadwal, COUNT(*) AS Banyak_Pemberhentian FROM rute
   GROUP BY ID_Jadwal;

SELECT ID_Jadwal, COUNT(*) AS Banyak_Pemberhentian FROM rute
   GROUP BY ID_Jadwal
   ORDER BY Banyak_Pemberhentian ASC;

SELECT ID_Jadwal, COUNT(*) AS Banyak_Pemberhentian FROM rute
   GROUP BY ID_Jadwal
   HAVING Banyak_Pemberhentian >= 10;

SELECT ID_Jadwal, COUNT(*) AS Banyak_Pemberhentian FROM rute
   WHERE ID_Stasiun IN ('YK','PWT','PSE','GMR','BD')
   GROUP BY ID_Jadwal
   HAVING Banyak_Pemberhentian > 2
   ORDER BY Banyak_Pemberhentian ASC;

Rangkaian

SELECT ID_Kereta, ID_Gerbong FROM rangkaian
   WHERE ID_Kereta IN ('KA001','KA002','KA003');

SELECT ID_Kereta, ID_Gerbong FROM rangkaian
   WHERE ID_Kereta IN ('KA001','KA002','KA003') AND Posisi_Gerbong IN (1,2);

SELECT ID_Kereta, ID_Gerbong FROM rangkaian
   WHERE ID_Kereta IN ('KA002','KA003') OR ID_Gerbong IN ('GRB021','GRB022')

SELECT ID_Kereta, ID_Gerbong FROM rangkaian
   WHERE NOT Posisi_Gerbong IN (3,4,5);

SELECT ID_Kereta, COUNT(*) AS Banyak_Gerbong FROM rangkaian
   GROUP BY ID_Kereta;

SELECT ID_Kereta, ID_Gerbong, Posisi_Gerbong FROM rangkaian
   WHERE ID_Kereta IN ('KA005','KA006','KA007')
   ORDER BY Posisi_Gerbong ASC;

SELECT ID_Gerbong, COUNT(*) AS Total_Digunakan FROM rangkaian
   GROUP BY ID_Gerbong
   HAVING COUNT(*) > 2;

SELECT ID_Gerbong, COUNT(*) AS Total_Digunakan FROM rangkaian
   WHERE NOT ID_Kereta IN ('KA008','KA009','KA010')
   GROUP BY ID_Gerbong
   HAVING COUNT(*) > 2
   ORDER BY COUNT(*) ASC;

Dinas

SELECT ID_Masinis, ID_Jadwal, Peran_Masinis FROM Dinas
   WHERE Peran_Masinis LIKE '%Utama';

SELECT ID_Masinis, ID_Jadwal, Peran_Masinis FROM Dinas
   WHERE Peran_Masinis LIKE '%Utama' AND ID_Masinis IN ('MSN001','MSN002');

SELECT ID_Masinis, ID_Jadwal, Peran_Masinis FROM Dinas
   WHERE Peran_Masinis LIKE '%Asisten' OR ID_Masinis IN ('MSN004','MSN005');

SELECT ID_Jadwal, Tanggal FROM dinas
   WHERE NOT Tanggal > '2026-10-0';

SELECT ID_Masinis, COUNT(*) AS Total_Berdinas FROM dinas
   GROUP BY ID_Masinis;

SELECT ID_Masinis, COUNT(*) AS Total_Berdinas FROM dinas
   GROUP BY ID_Masinis
   ORDER BY COUNT(*) ASC;

SELECT ID_Masinis, COUNT(*) AS Total_Berdinas FROM dinas
   GROUP BY ID_Masinis
   HAVING COUNT(*) > 3;

SELECT ID_Masinis, COUNT(*) AS Total_Berdinas FROM dinas
   WHERE Peran_Masinis LIKE '%Utama' AND Tanggal > '2026-10-0'
   GROUP BY ID_Masinis
   HAVING COUNT(*) > 2
   ORDER BY COUNT(*) DESC;


Tugas No 3
Masinis to Dinas

SELECT msn.Nama_Masinis, dns.Peran_Masinis, dns.Tanggal
   FROM masinis msn
   INNER JOIN dinas dns ON msn.ID_Masinis = dns.ID_Masinis;

SELECT msn.Nama_Masinis, dns.Peran_Masinis, dns.Tanggal
   FROM masinis msn
   LEFT JOIN dinas dns ON msn.ID_Masinis = dns.ID_Masinis;

SELECT msn.Nama_Masinis, dns.Peran_Masinis, dns.Tanggal
   FROM masinis msn
   RIGHT JOIN dinas dns ON msn.ID_Masinis = dns.ID_Masinis;

SELECT msn.Nama_Masinis, dns.Peran_Masinis, dns.Tanggal
   FROM masinis msn
   LEFT JOIN dinas dns ON msn.ID_Masinis = dns.ID_Masinis
   UNION
   SELECT msn.Nama_Masinis, dns.Peran_Masinis, dns.Tanggal
   FROM masinis msn
   RIGHT JOIN dinas dns ON msn.ID_Masinis = dns.ID_Masinis;

Lokomotif dengan Dinas

SELECT * FROM lokomotif CROSS JOIN dinas;

SELECT lok.No_Lokomotif, dns.Tanggal AS Tanggal_Digunakan
   FROM lokomotif lok
   INNER JOIN dinas dns ON lok.ID_Lokomotif = dns.ID_Lokomotif
   ORDER BY Tanggal_Digunakan;

SELECT lok.No_Lokomotif, dns.Tanggal AS Tanggal_Digunakan
   FROM lokomotif lok
   LEFT JOIN dinas dns ON lok.ID_Lokomotif = dns.ID_Lokomotif
   ORDER BY Tanggal_Digunakan ASC;

SELECT lok.No_Lokomotif, dns.Tanggal AS Tanggal_Digunakan
   FROM lokomotif lok
   RIGHT JOIN dinas dns ON lok.ID_Lokomotif = dns.ID_Lokomotif
   ORDER BY Tanggal_Digunakan ASC;

SELECT lok.No_Lokomotif, dns.Tanggal AS Tanggal_Digunakan
   FROM lokomotif lok
   LEFT JOIN dinas dns ON lok.ID_Lokomotif = dns.ID_Lokomotif
   UNION
   SELECT lok.No_Lokomotif, dns.Tanggal AS Tanggal_Digunakan
   FROM lokomotif lok
   RIGHT JOIN dinas dns ON lok.ID_Lokomotif = dns.ID_Lokomotif;

Jadwal Perjalanan dengan Dinas

SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, dns.Tanggal
   FROM jadwal_perjalanan jdw
   INNER JOIN dinas dns ON jdw.ID_Jadwal = dns.ID_Jadwal;

SELECT jdw.ID_Jadwal, dns.ID_Masinis, jdw.Hari_Jadwal, dns.Tanggal
   FROM jadwal_perjalanan jdw
   LEFT JOIN dinas dns ON jdw.ID_Jadwal = dns.ID_Jadwal;

SELECT jdw.ID_Jadwal, dns.ID_Masinis, jdw.Hari_Jadwal, dns.Tanggal
   FROM jadwal_perjalanan jdw
   RIGHT JOIN dinas dns ON jdw.ID_Jadwal = dns.ID_Jadwal;

SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, dns.Tanggal
   FROM jadwal_perjalanan jdw
   LEFT JOIN dinas dns ON jdw.ID_Jadwal = dns.ID_Jadwal
   UNION
   SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, dns.Tanggal
   FROM jadwal_perjalanan jdw
   RIGHT JOIN dinas dns ON jdw.ID_Jadwal = dns.ID_Jadwal;

SELECT sts.Nama_Stasiun, rut.ID_Jadwal
   FROM stasiun sts
   LEFT JOIN rute rut ON sts.ID_Stasiun = rut.ID_Stasiun
   ORDER BY rut.ID_Jadwal DESC;

SELECT sts.Nama_Stasiun, rut.ID_Jadwal
   FROM stasiun sts
   RIGHT JOIN rute rut ON sts.ID_Stasiun = rut.ID_Stasiun;

SELECT sts.Nama_Stasiun, rut.ID_Jadwal
   FROM stasiun sts
   LEFT JOIN rute rut ON sts.ID_Stasiun = rut.ID_Stasiun
   UNION
   SELECT sts.Nama_Stasiun, rut.ID_Jadwal
   FROM stasiun sts
   RIGHT JOIN rute rut ON sts.ID_Stasiun = rut.ID_Stasiun;

SELECT jdw.ID_Jadwal, rut.ID_Stasiun, rut.Urutan_Stasiun
   FROM jadwal_perjalanan jdw
   INNER JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal;

SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, rut.ID_Rute, rut.ID_Stasiun, rut.Urutan_Stasiun
FROM jadwal_perjalanan jdw
LEFT JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal
ORDER BY jdw.ID_Jadwal, rut.Urutan_Stasiun;

SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, rut.ID_Rute, rut.ID_Stasiun, rut.Urutan_Stasiun
FROM jadwal_perjalanan jdw
RIGHT JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal
ORDER BY jdw.ID_Jadwal, rut.Urutan_Stasiun;

SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, rut.ID_Stasiun, rut.Urutan_Stasiun
   FROM jadwal_perjalanan jdw
   LEFT JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal
   UNION
   SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, rut.ID_Stasiun, rut.Urutan_Stasiun
   FROM jadwal_perjalanan jdw
   RIGHT JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal;

SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, rut.ID_Stasiun, rut.Urutan_Stasiun
   FROM jadwal_perjalanan jdw
   RIGHT JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal
   ORDER BY jdw.ID_Jadwal, rut.Urutan_Stasiun;

SELECT jdw.ID_Jadwal, jdw.Hari_Jadwal, rut.ID_Stasiun, rut.Urutan_Stasiun
   FROM jadwal_perjalanan jdw
   LEFT JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal
   ORDER BY jdw.ID_Jadwal, rut.Urutan_Stasiun;

SELECT ka.Nama_Kereta, jdw.Hari_Jadwal
   FROM kereta_api ka
   INNER JOIN jadwal_perjalanan jdw ON ka.ID_Kereta = jdw.ID_Kereta;

SELECT ka.Nama_Kereta, jdw.Hari_Jadwal
   FROM kereta_api ka
   LEFT JOIN jadwal_perjalanan jdw ON ka.ID_Kereta = jdw.ID_Kereta;

SELECT ka.Nama_Kereta, jdw.Hari_Jadwal
   FROM kereta_api ka
   RIGHT JOIN jadwal_perjalanan jdw ON ka.ID_Kereta = jdw.ID_Kereta;

SELECT ka.Nama_Kereta, jdw.Hari_Jadwal
   FROM kereta_api ka
   LEFT JOIN jadwal_perjalanan jdw ON ka.ID_Kereta = jdw.ID_Kereta
   UNION
   SELECT ka.Nama_Kereta, jdw.Hari_Jadwal
   FROM kereta_api ka
   RIGHT JOIN jadwal_perjalanan jdw ON ka.ID_Kereta = jdw.ID_Kereta;

SELECT * FROM kereta_api CROSS JOIN rangkaian;

SELECT ka.Nama_Kereta, rgk.ID_Gerbong, rgk.Posisi_Gerbong
   FROM kereta_api ka
   INNER JOIN rangkaian rgk ON ka.ID_Kereta = rgk.ID_Kereta;

SELECT ka.Nama_Kereta, rgk.ID_Gerbong, rgk.Posisi_Gerbong
   FROM kereta_api ka
   LEFT JOIN rangkaian rgk ON ka.ID_Kereta = rgk.ID_Kereta;

SELECT ka.Nama_Kereta, rgk.ID_Gerbong, rgk.Posisi_Gerbong
   FROM kereta_api ka
   LEFT JOIN rangkaian rgk ON ka.ID_Kereta = rgk.ID_Kereta
   UNION
   SELECT ka.Nama_Kereta, rgk.ID_Gerbong, rgk.Posisi_Gerbong
   FROM kereta_api ka
   RIGHT JOIN rangkaian rgk ON ka.ID_Kereta = rgk.ID_Kereta;

SELECT rgk.ID_Kereta, grb.No_Gerbong, grb.Kelas_Gerbong
   FROM gerbong grb
   LEFT JOIN rangkaian rgk ON grb.ID_Gerbong = rgk.ID_Gerbong
   UNION
   SELECT rgk.ID_Kereta, grb.No_Gerbong, grb.Kelas_Gerbong
   FROM gerbong grb
   RIGHT JOIN rangkaian rgk ON grb.ID_Gerbong = rgk.ID_Gerbong

SELECT msn.Nama_Masinis, lok.No_Lokomotif, jdw.Hari_Jadwal AS Hari, dns.Tanggal, jdw.Jam_Keberangkatan_Awal,
jdw.Jam_Kedatangan_Akhir, ka.Nama_Kereta, sts.Nama_Stasiun, rut.Urutan_Stasiun AS Pemberhentian_Ke
FROM dinas dns
INNER JOIN masinis msn ON dns.ID_Masinis = msn.ID_Masinis
INNER JOIN lokomotif lok ON dns.ID_Lokomotif = lok.ID_Lokomotif
INNER JOIN jadwal_perjalanan jdw ON dns.ID_Jadwal = jdw.ID_Jadwal
INNER JOIN kereta_api ka ON jdw.ID_Kereta = ka.ID_Kereta
INNER JOIN rute rut ON jdw.ID_Jadwal = rut.ID_Jadwal
INNER JOIN stasiun sts ON rut.ID_Stasiun = sts.ID_Stasiun
WHERE msn.ID_Masinis = 'MSN001' AND dns.Tanggal = '2026-09-28'
ORDER BY rut.Urutan_Stasiun;