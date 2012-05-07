#ifndef ALIANALYSISTASKSAQA_H
#define ALIANALYSISTASKSAQA_H

// $Id$

class TClonesArray;
class TString;
class AliVTrack;
class AliVCluster;
class TList;
class TH1F;
class TH2F;

#include "AliAnalysisTaskSE.h"

class AliAnalysisTaskSAQA : public AliAnalysisTaskSE {
 public:
  AliAnalysisTaskSAQA();
  AliAnalysisTaskSAQA(const char *name);
  virtual ~AliAnalysisTaskSAQA();

  void                        UserCreateOutputObjects();
  void                        UserExec(Option_t *option);
  void                        Terminate(Option_t *option);

  void                        SetClusName(const char *n)                           { fCaloName      = n          ; }
  void                        SetTracksName(const char *n)                         { fTracksName    = n          ; }
  void                        SetTrgClusName(const char *n)                        { fTrgClusName   = n          ; }
  void                        SetHistoBins(Int_t nbins, Float_t min, Float_t max)  { fNbins = nbins; fMinPt = min; fMaxPt = max; }
  void                        SetCellEnergyCut(Float_t cut)                        { fCellEnergyCut = cut        ; }

 protected:

  AliVTrack                  *GetTrack(const Int_t i)                      const;
  Int_t                       GetNumberOfTracks()                          const;
  AliVCluster                *GetCaloCluster(const Int_t i)                const;
  Int_t                       GetNumberOfCaloClusters()                    const;
  AliVCluster                *GetTrgCluster(const Int_t i)                 const;
  Int_t                       GetNumberOfTrgClusters()                     const;
  Bool_t                      AcceptTrack(AliVTrack* /*track*/)            const;
  void                        FillHistograms()                                  ;
  void                        RetrieveEventObjects()                            ;
  void                        DoCellLoop(Float_t &sum, Float_t &sum_cut)        ;
  Float_t                     DoTriggerPrimitives()                             ;
  Float_t                     DoTriggerClusLoop()                               ;
  Float_t                     DoTrackLoop()                                     ;
  Float_t                     DoClusterLoop()                                   ;

  TList                      *fOutput;                 // Output list
  Float_t                     fCellEnergyCut;          // Energy cell cut
  TString                     fTracksName;             // Name of track collection
  TString                     fCaloName;               // Name of calo cluster collection
  TString                     fTrgClusName;            // Name of trg clus name
  TClonesArray               *fTracks;                 //!Tracks
  TClonesArray               *fCaloClusters;           //!Clusters
  TClonesArray               *fJets;                   //!Jets
  TClonesArray               *fTrgClusters;            //!Trg Clusters
  AliCentrality              *fCent;                   // Event centrality
  TH1F                       *fHistCentrality;         // Event centrality distribution
  TH2F                       *fHistTracksCent;         // Number of tracks vs. centrality
  TH2F                       *fHistClusCent;           // Number of clusters vs. centrality
  TH2F                       *fHistMaxL1Cent;          // Maximum L1 time sum amplitude vs. centrality
  TH1F                       *fHistTracksPt;           // Pt spectrum of tracks
  TH1F                       *fHistClustersEnergy;     // Energy spectrum of clusters
  TH2F                       *fHistEoverP;             // E/P vs. E
  TH2F                       *fHistTrPhiEta;           // Phi-Eta distribution of tracks
  TH2F                       *fHistClusPhiEta;         // Phi-Eta distribution of clusters
  TH1F                       *fHistMaxTrgCluster;      // Energy distribution of max trigger clusters
  TH2F                       *fHistMaxTrgClusVSMaxL1;  // Max trigger cluster vs. max L1 time sum amplitude
  TH1F                       *fHistClusPhiCorr;        // Clusters phi correlations
  TH1F                       *fHistTracksPhiCorr;      // Tracks phi correlations
  TH2F                       *fHistChVSneCells;        // Charged vs. neutral (cells) energy
  TH2F                       *fHistChVSneClus;         // Charged vs. neutral (clusters) energy
  TH2F                       *fHistChVSneCorrCells;    // Charged vs. neutral (corrected cells) energy
  TH1F                       *fHistTrackPhi[5];        // Phi distribution of hybrid tracks
  TH1F                       *fHistTrackEta[5];        // Eta distribution of hybrid tracks

  Int_t                       fNbins;                  // No. of pt bins
  Float_t                     fMinPt;                  // Min pt
  Float_t                     fMaxPt;                  // Max pt

 private:
  AliAnalysisTaskSAQA(const AliAnalysisTaskSAQA&);            // not implemented
  AliAnalysisTaskSAQA &operator=(const AliAnalysisTaskSAQA&); // not implemented

  ClassDef(AliAnalysisTaskSAQA, 1) // Quality task for Emcal analysis
};
#endif
